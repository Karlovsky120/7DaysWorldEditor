#include "MainFrame.h"
#include "OpenGLCanvas.h"

#include "wx\sizer.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {

  wxMenu *menuFile = new wxMenu;
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
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

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(wxID_EXIT, MainFrame::OnExit)
wxEND_EVENT_TABLE()