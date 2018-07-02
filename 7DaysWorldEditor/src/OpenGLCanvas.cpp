#include "openGLCanvas.h"

#include "OpenGLInitializer.h"

OpenGLCanvas::OpenGLCanvas(wxFrame* parent, int* args) :
    wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE) {
    context = new wxGLContext(this);

    while (!IsShown()) {
    };  // Force the Shown
    wxGLCanvas::SetCurrent(*context);

    std::string error;
    if (!OpenGLInitializer::InitializeOpenGL(&error)) {
        wxMessageBox(
            wxString("GLEW Error: ") +
            wxString(error),
            _("OpenGl ERROR"),
            wxOK | wxICON_EXCLAMATION
        );
        exit(4001);
    }

    SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    scene = std::make_unique<Scene>();
}

OpenGLCanvas::~OpenGLCanvas() {
    delete context;
}

void OpenGLCanvas::resized(wxSizeEvent& evt) {
    const wxSize ClientSize = GetClientSize();
    glViewport(0, 0, ClientSize.x, ClientSize.y);

    Refresh();
}

void OpenGLCanvas::render(wxPaintEvent& evt) {
    if (!IsShown()) return;

    wxGLCanvas::SetCurrent(*context);
    wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

    while (true) {
        scene->render();

        SwapBuffers();
    }
}

BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
EVT_SIZE(OpenGLCanvas::resized)
EVT_PAINT(OpenGLCanvas::render)
END_EVENT_TABLE()
