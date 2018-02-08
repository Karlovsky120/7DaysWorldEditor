#include "MainFrame.h"

#include "SaveDeflater.h"
#include "openGLCanvas.h"

#include "wx\sizer.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {

	wxMenu *menuFile = new wxMenu;
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	/*wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);*/

	wxMenu *menuTools = new wxMenu;
	menuTools->Append(ID_DEFLATESAVE, "Deflate Save", "Deflates a save file sometimes to under 50% of it's original size");

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuTools, "&Tools");
	//menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);

  wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
  int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, WX_GL_MAJOR_VERSION, 4, WX_GL_MINOR_VERSION, 4, 0};

  OpenGLCanvas *glPane = new OpenGLCanvas((wxFrame*)this, args);
  sizer->Add(glPane, 1, wxEXPAND);

  this->SetSizer(sizer);
  this->SetAutoLayout(true);

	CreateStatusBar();
	SetStatusText("Ready");
}

void MainFrame::OnExit(wxCommandEvent& event) {
	Close(true);
}

/*void MainFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("This is a wxWidgets' Hello world sample",
				 "About Hello World", wxOK | wxICON_INFORMATION);
}*/

void MainFrame::OnDeflateSave(wxCommandEvent& event) {



	SaveDeflater::deflate(this);
	//wxLogMessage("Hello world from wxWidgets!");
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(ID_DEFLATESAVE, MainFrame::OnDeflateSave)
EVT_MENU(wxID_EXIT, MainFrame::OnExit)
wxEND_EVENT_TABLE()