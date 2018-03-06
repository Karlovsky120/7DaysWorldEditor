#include "openGLCanvas.h"

#include "CameraTransformation.h"
#include "Loader.h"
#include "Renderer.h"
#include "StaticShader.h"
#include "Mesh.h"
#include "Texture.h"
#include "TexturedMesh.h"
#include "Transformation.h"
#include "Entity.h"

OpenGLCanvas::OpenGLCanvas(wxFrame* parent, int* args) :
	wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE) {
	context = new wxGLContext(this);

	while (!IsShown()) {};  // Force the Shown
	wxGLCanvas::SetCurrent(*context);

	/// Init OpenGL
	GLenum err = glewInit();
	if (err != GL_NO_ERROR) {
		wxMessageBox(
			wxString("GLEW Error: ") +
			wxString(glewGetErrorString(err)),
			_("OpenGl ERROR"),
			wxOK | wxICON_EXCLAMATION
		);
		exit(4001);
	}

	// To avoid flashing on MSW
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

	scene->render();

	SwapBuffers();
}

BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
EVT_SIZE(OpenGLCanvas::resized)
EVT_PAINT(OpenGLCanvas::render)
END_EVENT_TABLE()
