#pragma once

#include "Scene.h"

#include "wxWidgets.h"
#include "wx\glcanvas.h"

#include <memory>

class Transformation;

class OpenGLCanvas : public wxGLCanvas {
public:
    OpenGLCanvas(wxFrame* parent, int* args);
    virtual ~OpenGLCanvas();

    void resized(wxSizeEvent& evt);
    void render(wxPaintEvent& evt);

private:
    std::unique_ptr<Scene> scene;
    wxGLContext*	context;

    wxDECLARE_EVENT_TABLE();
};
