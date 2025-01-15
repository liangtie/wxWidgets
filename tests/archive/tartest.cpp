///////////////////////////////////////////////////////////////////////////////
// Name:        tests/tartest.cpp
// Purpose:     Test the tar classes
// Author:      Mike Wetherell
// Copyright:   (c) 2004 Mike Wetherell
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include "testprec.h"

#ifndef WX_PRECOMP
#   include "wx/wx.h"
#endif

#if wxUSE_STREAMS

#include "archivetest.h"
#include "wx/tarstrm.h"

using std::string;


///////////////////////////////////////////////////////////////////////////////
// Tar suite

class tartest : public ArchiveTestSuite
{
public:
    tartest();

    void runTest() wxOVERRIDE { DoRunTest(); }

protected:
    CppUnit::Test *makeTest(string descr, int options,
                            bool genericInterface,
                            const wxString& archiver,
                            const wxString& unarchiver) wxOVERRIDE;
};

tartest::tartest()
  : ArchiveTestSuite("tar")
{
    AddArchiver(wxT("tar cf %s *"));
    AddUnArchiver(wxT("tar xf %s"));
}

CppUnit::Test *tartest::makeTest(
    string descr,
    int   options,
    bool  genericInterface,
    const wxString& archiver,
    const wxString& unarchiver)
{
    if ((options & Stub) && (options & PipeIn) == 0)
        return NULL;

    if (genericInterface)
    {
        return NEW_DEBUG ArchiveTestCase<wxArchiveClassFactory>(
                            descr, NEW_DEBUG wxTarClassFactory,
                            options, archiver, unarchiver);
    }

    return NEW_DEBUG ArchiveTestCase<wxTarClassFactory>(
                        descr, NEW_DEBUG wxTarClassFactory,
                        options, archiver, unarchiver);
}

CPPUNIT_TEST_SUITE_REGISTRATION(tartest);
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(tartest, "archive/tar");

#endif // wxUSE_STREAMS
