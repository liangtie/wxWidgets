/////////////////////////////////////////////////////////////////////////////
// Name:        src/common/imagall.cpp
// Purpose:     wxImage access all handler
// Author:      Sylvain Bougnoux
// Copyright:   (c) Sylvain Bougnoux
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"


#if wxUSE_IMAGE

#ifndef WX_PRECOMP
    #include "wx/image.h"
#endif

//-----------------------------------------------------------------------------
// This function allows dynamic access to all image handlers compile within
// the library. This function should be in a separate file as some compilers
// link against the whole object file as long as just one of is function is called!

void wxInitAllImageHandlers()
{
#if wxUSE_LIBPNG
  wxImage::AddHandler( NEW_DEBUG wxPNGHandler );
#endif
#if wxUSE_LIBJPEG
  wxImage::AddHandler( NEW_DEBUG wxJPEGHandler );
#endif
#if wxUSE_LIBTIFF
  wxImage::AddHandler( NEW_DEBUG wxTIFFHandler );
#endif
#if wxUSE_GIF
  wxImage::AddHandler( NEW_DEBUG wxGIFHandler );
#endif
#if wxUSE_PNM
  wxImage::AddHandler( NEW_DEBUG wxPNMHandler );
#endif
#if wxUSE_PCX
  wxImage::AddHandler( NEW_DEBUG wxPCXHandler );
#endif
#if wxUSE_IFF
  wxImage::AddHandler( NEW_DEBUG wxIFFHandler );
#endif
#if wxUSE_ICO_CUR
  wxImage::AddHandler( NEW_DEBUG wxICOHandler );
  wxImage::AddHandler( NEW_DEBUG wxCURHandler );
  wxImage::AddHandler( NEW_DEBUG wxANIHandler );
#endif
#if wxUSE_TGA
  wxImage::AddHandler( NEW_DEBUG wxTGAHandler );
#endif
#if wxUSE_XPM
  wxImage::AddHandler( NEW_DEBUG wxXPMHandler );
#endif
}

#endif // wxUSE_IMAGE
