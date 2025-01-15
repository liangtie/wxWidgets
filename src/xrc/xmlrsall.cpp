/////////////////////////////////////////////////////////////////////////////
// Name:        src/xrc/xmlrsall.cpp
// Purpose:     wxXmlResource::InitAllHandlers
// Author:      Vaclav Slavik
// Created:     2000/03/05
// Copyright:   (c) 2000 Vaclav Slavik
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"


#if wxUSE_XRC

#include "wx/xrc/xmlres.h"
#include "wx/xrc/xh_all.h"

void wxXmlResource::InitAllHandlers()
{
    // these are the handlers, which we always have
    AddHandler(NEW_DEBUG wxUnknownWidgetXmlHandler);
    AddHandler(NEW_DEBUG wxBitmapXmlHandler);
    AddHandler(NEW_DEBUG wxIconXmlHandler);
    AddHandler(NEW_DEBUG wxDialogXmlHandler);
    AddHandler(NEW_DEBUG wxPanelXmlHandler);
    AddHandler(NEW_DEBUG wxSizerXmlHandler);
    AddHandler(NEW_DEBUG wxFrameXmlHandler);
    AddHandler(NEW_DEBUG wxScrolledWindowXmlHandler);

    // these are configurable handlers
    //
    // please keep them in alphabetical order of wxUSE_XXX guards
#if wxUSE_ACTIVITYINDICATOR
    AddHandler(NEW_DEBUG wxActivityIndicatorXmlHandler);
#endif
#if wxUSE_ANIMATIONCTRL
    AddHandler(NEW_DEBUG wxAnimationCtrlXmlHandler);
#endif
#if wxUSE_BANNERWINDOW
    AddHandler(NEW_DEBUG wxBannerWindowXmlHandler);
#endif
#if wxUSE_BITMAPCOMBOBOX
    AddHandler(NEW_DEBUG wxBitmapComboBoxXmlHandler);
#endif
#if wxUSE_BMPBUTTON
    AddHandler(NEW_DEBUG wxBitmapButtonXmlHandler);
#endif
#if wxUSE_BOOKCTRL
    AddHandler(NEW_DEBUG wxPropertySheetDialogXmlHandler);
#endif
#if wxUSE_BUTTON
    AddHandler(NEW_DEBUG wxStdDialogButtonSizerXmlHandler);
    AddHandler(NEW_DEBUG wxButtonXmlHandler);
#endif
#if wxUSE_CALENDARCTRL
    AddHandler(NEW_DEBUG wxCalendarCtrlXmlHandler);
#endif
#if wxUSE_CHECKBOX
    AddHandler(NEW_DEBUG wxCheckBoxXmlHandler);
#endif
#if wxUSE_CHECKLISTBOX
    AddHandler(NEW_DEBUG wxCheckListBoxXmlHandler);
#endif
#if wxUSE_CHOICE
    AddHandler(NEW_DEBUG wxChoiceXmlHandler);
#endif
#if wxUSE_CHOICEBOOK
    AddHandler(NEW_DEBUG wxChoicebookXmlHandler);
#endif
#if wxUSE_COLLPANE
    AddHandler(NEW_DEBUG wxCollapsiblePaneXmlHandler);
#endif
#if wxUSE_COLOURPICKERCTRL
    AddHandler(NEW_DEBUG wxColourPickerCtrlXmlHandler);
#endif
#if wxUSE_COMBOBOX
    AddHandler(NEW_DEBUG wxComboBoxXmlHandler);
#endif
#if wxUSE_COMBOCTRL
    AddHandler(NEW_DEBUG wxComboCtrlXmlHandler);
#endif
#if wxUSE_COMMANDLINKBUTTON
    AddHandler(NEW_DEBUG wxCommandLinkButtonXmlHandler);
#endif
#if wxUSE_DATAVIEWCTRL
    AddHandler(NEW_DEBUG wxDataViewXmlHandler);
#endif
#if wxUSE_DATEPICKCTRL
    AddHandler(NEW_DEBUG wxDateCtrlXmlHandler);
#endif
#if wxUSE_DIRDLG
    AddHandler(NEW_DEBUG wxGenericDirCtrlXmlHandler);
#endif
#if wxUSE_DIRPICKERCTRL
    AddHandler(NEW_DEBUG wxDirPickerCtrlXmlHandler);
#endif
#if wxUSE_EDITABLELISTBOX
    AddHandler(NEW_DEBUG wxEditableListBoxXmlHandler);
#endif
#if wxUSE_FILECTRL
    AddHandler(NEW_DEBUG wxFileCtrlXmlHandler);
#endif
#if wxUSE_FILEPICKERCTRL
    AddHandler(NEW_DEBUG wxFilePickerCtrlXmlHandler);
#endif
#if wxUSE_FONTPICKERCTRL
    AddHandler(NEW_DEBUG wxFontPickerCtrlXmlHandler);
#endif
#if wxUSE_GAUGE
    AddHandler(NEW_DEBUG wxGaugeXmlHandler);
#endif
#if wxUSE_GRID
    AddHandler( NEW_DEBUG wxGridXmlHandler);
#endif
#if wxUSE_HTML
    AddHandler(NEW_DEBUG wxHtmlWindowXmlHandler);
    AddHandler(NEW_DEBUG wxSimpleHtmlListBoxXmlHandler);
#endif
#if wxUSE_HYPERLINKCTRL
    AddHandler( NEW_DEBUG wxHyperlinkCtrlXmlHandler);
#endif
#if wxUSE_INFOBAR
    AddHandler(NEW_DEBUG wxInfoBarXmlHandler);
#endif
#if wxUSE_LISTBOOK
    AddHandler(NEW_DEBUG wxListbookXmlHandler);
#endif
#if wxUSE_LISTBOX
    AddHandler(NEW_DEBUG wxListBoxXmlHandler);
#endif
#if wxUSE_LISTCTRL
    AddHandler(NEW_DEBUG wxListCtrlXmlHandler);
#endif
#if wxUSE_MDI
    AddHandler(NEW_DEBUG wxMdiXmlHandler);
#endif
#if wxUSE_MENUS
    AddHandler(NEW_DEBUG wxMenuXmlHandler);
#if wxUSE_MENUBAR
    AddHandler(NEW_DEBUG wxMenuBarXmlHandler);
#endif
#endif
#if wxUSE_NOTEBOOK
    AddHandler(NEW_DEBUG wxNotebookXmlHandler);
#endif
#if wxUSE_ODCOMBOBOX
    AddHandler(NEW_DEBUG wxOwnerDrawnComboBoxXmlHandler);
#endif
#if wxUSE_RADIOBOX
    AddHandler(NEW_DEBUG wxRadioBoxXmlHandler);
#endif
#if wxUSE_RADIOBTN
    AddHandler(NEW_DEBUG wxRadioButtonXmlHandler);
#endif
#if wxUSE_SCROLLBAR
    AddHandler(NEW_DEBUG wxScrollBarXmlHandler);
#endif
#if wxUSE_SEARCHCTRL
    AddHandler(NEW_DEBUG wxSearchCtrlXmlHandler);
#endif
#if wxUSE_BOOKCTRL
    AddHandler(NEW_DEBUG wxSimplebookXmlHandler);
#endif
#if wxUSE_SLIDER
    AddHandler(NEW_DEBUG wxSliderXmlHandler);
#endif
#if wxUSE_SPINBTN
    AddHandler(NEW_DEBUG wxSpinButtonXmlHandler);
#endif
#if wxUSE_SPINCTRL
    AddHandler(NEW_DEBUG wxSpinCtrlXmlHandler);
    AddHandler(NEW_DEBUG wxSpinCtrlDoubleXmlHandler);
#endif
#if wxUSE_SPLITTER
    AddHandler(NEW_DEBUG wxSplitterWindowXmlHandler);
#endif
#if wxUSE_STATBMP
    AddHandler(NEW_DEBUG wxStaticBitmapXmlHandler);
#endif
#if wxUSE_STATBOX
    AddHandler(NEW_DEBUG wxStaticBoxXmlHandler);
#endif
#if wxUSE_STATLINE
    AddHandler(NEW_DEBUG wxStaticLineXmlHandler);
#endif
#if wxUSE_STATTEXT
    AddHandler(NEW_DEBUG wxStaticTextXmlHandler);
#endif
#if wxUSE_STATUSBAR
    AddHandler(NEW_DEBUG wxStatusBarXmlHandler);
#endif
#if wxUSE_TEXTCTRL
    AddHandler(NEW_DEBUG wxTextCtrlXmlHandler);
#endif
#if wxUSE_TOGGLEBTN
    AddHandler(NEW_DEBUG wxToggleButtonXmlHandler);
#endif
#if wxUSE_TIMEPICKCTRL
    AddHandler(NEW_DEBUG wxTimeCtrlXmlHandler);
#endif
#if wxUSE_TOOLBAR
    AddHandler(NEW_DEBUG wxToolBarXmlHandler);
#endif
#if wxUSE_TOOLBOOK
    AddHandler(NEW_DEBUG wxToolbookXmlHandler);
#endif
#if wxUSE_TREEBOOK
    AddHandler(NEW_DEBUG wxTreebookXmlHandler);
#endif
#if wxUSE_TREECTRL
    AddHandler(NEW_DEBUG wxTreeCtrlXmlHandler);
#endif
#if wxUSE_WIZARDDLG
    AddHandler(NEW_DEBUG wxWizardXmlHandler);
#endif
}

#endif // wxUSE_XRC
