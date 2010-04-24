#!/usr/bin/env python

# Run this script from top-level wxWidgets directory to update the contents of
# include/wx/intl.h and src/common/intl.cpp using information from langtabl.txt
#
# Warning: error detection and reporting here is rudimentary, check if the
# files were updated correctly with "svn diff" before committing them!

import os
import string
import sys

def ReadTable():
    table = []
    try:
        f = open('misc/languages/langtabl.txt')
    except:
        print "Did you run the script from top-level wxWidgets directory?"
        raise

    for i in f.readlines():
        ispl = i.split()
        table.append((ispl[0], ispl[1], ispl[2], ispl[3], ispl[4], string.join(ispl[5:])))
    f.close()
    return table


def WriteEnum(f, table):
   f.write("""
/**
    The languages supported by wxLocale.

    This enum is generated by misc/languages/genlang.py
    When making changes, please put them into misc/languages/langtabl.txt
*/
enum wxLanguage
{
    /// User's default/preffered language as got from OS.
    wxLANGUAGE_DEFAULT,

    /// Unknown language, returned if wxLocale::GetSystemLanguage fails.
    wxLANGUAGE_UNKNOWN,

""");
   knownLangs = []
   for i in table:
       if i[0] not in knownLangs:
          f.write('    %s,\n' % i[0])
          knownLangs.append(i[0])
   f.write("""
    /// For custom, user-defined languages.
    wxLANGUAGE_USER_DEFINED
};

""")


def WriteTable(f, table):
   all_langs = []
   all_sublangs = []

   lngtable = ''
   ifdefs = ''

   for i in table:
       ican = '"%s"' % i[1]
       if ican == '"-"': ican = '""'
       ilang = i[2]
       if ilang == '-': ilang = '0'
       isublang = i[3]
       if isublang == '-': isublang = '0'
       if (i[4] == "LTR") :
           ilayout = "wxLayout_LeftToRight"
       elif (i[4] == "RTL"):
           ilayout = "wxLayout_RightToLeft"
       else:
           print "ERROR: Invalid value for the layout direction";
       lngtable += '   LNG(%-38s %-7s, %-15s, %-34s, %s, %s)\n' % \
                     ((i[0]+','), ican, ilang, isublang, ilayout, i[5])
       if ilang not in all_langs: all_langs.append(ilang)
       if isublang not in all_sublangs: all_sublangs.append(isublang)

   for s in all_langs:
       if s != '0':
           ifdefs += '#ifndef %s\n#define %s (0)\n#endif\n' % (s, s)
   for s in all_sublangs:
       if s != '0' and s != 'SUBLANG_DEFAULT':
           ifdefs += '#ifndef %s\n#define %s SUBLANG_DEFAULT\n#endif\n' % (s, s)

   f.write("""
// This table is generated by misc/languages/genlang.py
// When making changes, please put them into misc/languages/langtabl.txt

#if !defined(__WIN32__) || defined(__WXMICROWIN__)

#define SETWINLANG(info,lang,sublang)

#else

#define SETWINLANG(info,lang,sublang) \\
    info.WinLang = lang, info.WinSublang = sublang;

%s

#endif // __WIN32__

#define LNG(wxlang, canonical, winlang, winsublang, layout, desc) \\
    info.Language = wxlang;                               \\
    info.CanonicalName = wxT(canonical);                  \\
    info.LayoutDirection = layout;                        \\
    info.Description = wxT(desc);                         \\
    SETWINLANG(info, winlang, winsublang)                 \\
    AddLanguage(info);

void wxLocale::InitLanguagesDB()
{
   wxLanguageInfo info;
   wxStringTokenizer tkn;

%s
}
#undef LNG

""" % (ifdefs, lngtable))


def ReplaceGeneratedPartOfFile(fname, func):
    """
        Replaces the part of file marked with the special comments with the
        output of func.

        fname is the name of the input file and func must be a function taking
        a file and language table on input and writing the appropriate chunk to
        this file, e.g. WriteEnum or WriteTable.
    """
    fin = open(fname, 'rt')
    fnameNew = fname + '.new'
    fout = open(fnameNew, 'wt')
    betweenBeginAndEnd = 0
    afterEnd = 0
    for l in fin.readlines():
        if l == '// --- --- --- generated code begins here --- --- ---\n':
            if betweenBeginAndEnd or afterEnd:
                print 'Unexpected starting comment.'
            betweenBeginAndEnd = 1
            fout.write(l)
            func(fout, table)
        elif l == '// --- --- --- generated code ends here --- --- ---\n':
            if not betweenBeginAndEnd:
                print 'End comment found before the starting one?'
                break

            betweenBeginAndEnd = 0
            afterEnd = 1

        if not betweenBeginAndEnd:
            fout.write(l)

    if not afterEnd:
        print 'Failed to process %s.' % fname
        os.remove(fnameNew)
        sys.exit(1)

    os.remove(fname)
    os.rename(fnameNew, fname)

table = ReadTable()
ReplaceGeneratedPartOfFile('include/wx/language.h', WriteEnum)
ReplaceGeneratedPartOfFile('interface/wx/language.h', WriteEnum)
ReplaceGeneratedPartOfFile('src/common/languageinfo.cpp', WriteTable)
