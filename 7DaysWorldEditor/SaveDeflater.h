#pragma once
#include "wxwidgets.h"

class SaveDeflater {
public:
	static void deflate(wxFrame *mainFrame);
private:
	SaveDeflater();
	~SaveDeflater();
};


/*class SaveDeflaterProgressFrame : public wxFrame {
public:
	SaveDeflaterProgressFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
private:
	void onExit(wxCommandEvent &event);
	wxDECLARE_EVENT_TABLE();
};*/

