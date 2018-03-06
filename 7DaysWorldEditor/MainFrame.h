#pragma once

#include "wxwidgets.h"

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
	void OnExit(wxCommandEvent &event);

	wxDECLARE_EVENT_TABLE();
};
