#pragma once

#include "wxWidgets.h"
#define GLEW_STATIC
#include "GL\glew.h"
#include "wx\glcanvas.h"

#include "Scene.h"

#include <memory>

class Transformation;

class OpenGLCanvas : public wxGLCanvas {
  wxGLContext*	context;

public:
  OpenGLCanvas(wxFrame* parent, int* args);
  virtual ~OpenGLCanvas();

  void resized(wxSizeEvent& evt);
  void render(wxPaintEvent& evt);

private:
  std::unique_ptr<Scene> scene;

  wxDECLARE_EVENT_TABLE();
};