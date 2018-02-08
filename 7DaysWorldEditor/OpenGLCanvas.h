#pragma once

#include "wxWidgets.h"
#define GLEW_STATIC
#include "GL\glew.h"
#include "wx\glcanvas.h"

#include "Scene.h"

#include <memory>

class Transformation;

class OpenGLCanvas : public wxGLCanvas {
  wxGLContext*	m_context;

public:
  OpenGLCanvas(wxFrame* parent, int* args);
  virtual ~OpenGLCanvas();

  void resized(wxSizeEvent& evt);

  int getWidth() const;
  int getHeight() const;
  void applyViewportTransformation(Transformation *cameraTransformation);

  void render(wxPaintEvent& evt);

  // events
  void mouseMoved(wxMouseEvent& event);
  void mouseDown(wxMouseEvent& event);
  void mouseWheelMoved(wxMouseEvent& event);
  void mouseReleased(wxMouseEvent& event);
  void rightClick(wxMouseEvent& event);
  void mouseLeftWindow(wxMouseEvent& event);
  void keyPressed(wxKeyEvent& event);
  void keyReleased(wxKeyEvent& event);

  DECLARE_EVENT_TABLE()

private:
  wxSize canvasSize;
  std::unique_ptr<Scene> scene;
};



/*
class openGLCanvas : public wxGLCanvas {
  void Render();
public:
  openGLCanvas(wxFrame* parent);
  ~openGLCanvas();
  void Paintit(wxPaintEvent& event);
protected:
  DECLARE_EVENT_TABLE()
};*/

