/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2007 - 2010 Steven Lamerton
// License:     GNU GPL 2 http://www.gnu.org/licenses/gpl-2.0.html
/////////////////////////////////////////////////////////////////////////////////

#ifndef FRMPROGRESS_H
#define FRMPROGRESS_H

#include <wx/dialog.h>

#if defined(__WXMSW__) && !defined(__MINGW32__)
	struct ITaskbarList3;
#endif

class ProgressListCtrl;
class wxButton;
class wxGauge;
class wxBitmapButton;
class wxBitmapToggleButton;

enum{
	ID_FRMPROGRESS = wxID_HIGHEST + 1,
	ID_PANEL_PROGRESS,
	ID_PROGRESS_LIST,
	ID_PROGRESS_GAUGE,
    ID_PROGRESS_AUTOSCROLL
};

class frmProgress: public wxDialog
{
	DECLARE_EVENT_TABLE()

public:
	//Constructor
	frmProgress(wxWindow* parent, wxWindowID id, const wxString& caption);

	//Sets up all of the member vaiables
	void Init();

	//Creates the controls and sizers
	void CreateControls();

#if defined(__WXMSW__) && !defined(__MINGW32__)
	ITaskbarList3 *m_Taskbar;
    void SetTaskbar(ITaskbarList3 *bar) {m_Taskbar = bar;}
#endif

    void OnIdle(wxIdleEvent& event);
    void OnSize(wxSizeEvent& event);
	void OnOkClick(wxCommandEvent& event);
	void OnCancelClick(wxCommandEvent& event);
	void OnSaveClick(wxCommandEvent& event);
	void OnCloseClick(wxCommandEvent& event);
    wxBitmap GetBitmapResource(const wxString& name);

    void RequestUserAttention();
    void StartProgress();
    void FinishProgress();

	void IncrementGauge();
	void FinishGauge();

	ProgressListCtrl* m_List;
	wxButton* m_Cancel;
	wxBitmapButton* m_Save;
    wxBitmapToggleButton* m_Autoscroll;
	wxGauge* m_Gauge;
};

#endif
