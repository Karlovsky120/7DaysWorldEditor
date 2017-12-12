#pragma once

#include "wxWidgets.h"
#define GLEW_STATIC
#include "GL\glew.h"
#include "wx\glcanvas.h"

class BasicGLPane : public wxGLCanvas {
  wxGLContext*	m_context;

public:
  BasicGLPane(wxFrame* parent, int* args);
  virtual ~BasicGLPane();

  void resized(wxSizeEvent& evt);

  int getWidth();
  int getHeight();

  void render(wxPaintEvent& evt);
  void prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
  void prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);

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

