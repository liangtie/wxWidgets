///////////////////////////////////////////////////////////////////////////////
// Name:        wx/generic/private/addremovectrl.h
// Purpose:     Generic wxAddRemoveImpl implementation, also used in wxMSW
// Author:      Vadim Zeitlin
// Created:     2015-02-05
// Copyright:   (c) 2015 Vadim Zeitlin <vadim@wxwidgets.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_GENERIC_PRIVATE_ADDREMOVECTRL_H_
#define _WX_GENERIC_PRIVATE_ADDREMOVECTRL_H_

// ----------------------------------------------------------------------------
// wxAddRemoveImpl
// ----------------------------------------------------------------------------

class wxAddRemoveImpl : public wxAddRemoveImplWithButtons
{
public:
    wxAddRemoveImpl(wxAddRemoveAdaptor* adaptor,
                    wxAddRemoveCtrl* parent,
                    wxWindow* ctrlItems)
        : wxAddRemoveImplWithButtons(adaptor, parent, ctrlItems)
    {
        m_btnAdd = NEW_DEBUG wxButton(parent, wxID_ADD, GetAddButtonLabel(),
                                wxDefaultPosition, wxDefaultSize,
                                wxBU_EXACTFIT | wxBORDER_NONE);
        m_btnRemove = NEW_DEBUG wxButton(parent, wxID_REMOVE, GetRemoveButtonLabel(),
                                   wxDefaultPosition, wxDefaultSize,
                                   wxBU_EXACTFIT | wxBORDER_NONE);

        wxSizer* const sizerBtns = NEW_DEBUG wxBoxSizer(wxVERTICAL);
        sizerBtns->Add(m_btnAdd, wxSizerFlags().Expand());
        sizerBtns->Add(m_btnRemove, wxSizerFlags().Expand());

        wxSizer* const sizerTop = NEW_DEBUG wxBoxSizer(wxHORIZONTAL);
        sizerTop->Add(ctrlItems, wxSizerFlags(1).Expand());
        sizerTop->Add(sizerBtns, wxSizerFlags().Centre().Border(wxLEFT));
        parent->SetSizer(sizerTop);

        SetUpEvents();
    }

private:
    static wxString GetAddButtonLabel()
    {
#if wxUSE_UNICODE
        return wchar_t(0xFF0B); // FULLWIDTH PLUS SIGN
#else
        return "+";
#endif
    }

    static wxString GetRemoveButtonLabel()
    {
#if wxUSE_UNICODE
        return wchar_t(0x2012); // FIGURE DASH
#else
        return "-";
#endif
    }

};

#endif // _WX_GENERIC_PRIVATE_ADDREMOVECTRL_H_
