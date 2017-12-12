#pragma once

#include "wxwidgets.h"

enum {
	ID_DEFLATESAVE = 1
};

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
private:
	void OnDeflateSave(wxCommandEvent& event);
	void OnExit(wxCommandEvent &event);
	wxDECLARE_EVENT_TABLE();
};
