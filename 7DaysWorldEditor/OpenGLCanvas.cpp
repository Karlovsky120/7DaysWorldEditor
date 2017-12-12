#include "openGLCanvas.h"

// some useful events to use
void BasicGLPane::mouseMoved(wxMouseEvent& event) {}
void BasicGLPane::mouseDown(wxMouseEvent& event) {}
void BasicGLPane::mouseWheelMoved(wxMouseEvent& event) {}
void BasicGLPane::mouseReleased(wxMouseEvent& event) {}
void BasicGLPane::rightClick(wxMouseEvent& event) {}
void BasicGLPane::mouseLeftWindow(wxMouseEvent& event) {}
void BasicGLPane::keyPressed(wxKeyEvent& event) {}
void BasicGLPane::keyReleased(wxKeyEvent& event) {}

// Vertices and faces of a simple cube to demonstrate 3D render
// source: http://www.opengl.org/resources/code/samples/glut_examples/examples/cube.c
GLfloat v[8][3];
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3},{3, 2, 6, 7},{7, 6, 5, 4},
  {4, 5, 1, 0},{5, 6, 2, 1},{7, 4, 0, 3}};



BasicGLPane::BasicGLPane(wxFrame* parent, int* args) :
  wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE) {
  
  m_context = new wxGLContext(this);


  while (!IsShown()) {};  // Force the Shown
  wxGLCanvas::SetCurrent(*m_context);

  /// Init OpenGL
  GLenum err = glewInit();
  if (err != GL_NO_ERROR) {
    wxMessageBox(
      wxString("GLEW Error: ") +
      wxString(glewGetErrorString(err)),
      _("OpenGl ERROR"),
      wxOK | wxICON_EXCLAMATION
    );
    exit(4001); //
  }



  // To avoid flashing on MSW
  SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}

BasicGLPane::~BasicGLPane() {
  delete m_context;
}

void BasicGLPane::resized(wxSizeEvent& evt) {
  //	wxGLCanvas::OnSize(evt);

  Refresh();
}

/** Inits the OpenGL viewport for drawing in 3D. */
void BasicGLPane::prepare3DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y) {

  glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // Black Background
  glClearDepth(1.0f);	// Depth Buffer Setup
  glEnable(GL_DEPTH_TEST); // Enables Depth Testing
  glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  glEnable(GL_COLOR_MATERIAL);

  glViewport(topleft_x, topleft_y, bottomrigth_x - topleft_x, bottomrigth_y - topleft_y);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float ratio_w_h = (float)(bottomrigth_x - topleft_x) / (float)(bottomrigth_y - topleft_y);
  //gluPerspective(45 /*view angle*/, ratio_w_h, 0.1 /*clip close*/, 200 /*clip far*/);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}

/** Inits the OpenGL viewport for drawing in 2D. */
void BasicGLPane::prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y) {
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Black Background
  glEnable(GL_TEXTURE_2D);   // textures
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glViewport(topleft_x, topleft_y, bottomrigth_x - topleft_x, bottomrigth_y - topleft_y);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //gluOrtho2D(topleft_x, bottomrigth_x, bottomrigth_y, topleft_y);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int BasicGLPane::getWidth() {
  return GetSize().x;
}

int BasicGLPane::getHeight() {
  return GetSize().y;
}


void BasicGLPane::render(wxPaintEvent& evt) {
  if (!IsShown()) return;

  wxGLCanvas::SetCurrent(*m_context);
  wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

  glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
  };


  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  char *vertexShaderSource = "#version 330 core\nlayout(location = 0) in vec3 aPos;     void main() {    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);  }";

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  int  success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    wxMessageBox(
      wxString("GLEW Error: ") +
      wxString(infoLog),
      _("OpenGl ERROR"),
      wxOK | wxICON_EXCLAMATION
    );
  }


  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  char *fragmentShaderSource = "#version 330 core    \nout vec4 FragColor;    void main() {    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);  }";

  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);


  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    wxMessageBox(
      wxString("GLEW Error: ") +
      wxString(infoLog),
      _("OpenGl ERROR"),
      wxOK | wxICON_EXCLAMATION
    );
  }

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    wxMessageBox(
      wxString("GLEW Error: ") +
      wxString(infoLog),
      _("OpenGl ERROR"),
      wxOK | wxICON_EXCLAMATION
    );
  }


  glUseProgram(shaderProgram);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);


  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);


  SwapBuffers();

  // ------------- draw some 2D ----------------
  /*prepare2DViewport(0, 0, getWidth() / 2, getHeight());
  glLoadIdentity();

  // white background
  glColor4f(0, 1, 1, 1);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(getWidth(), 0, 0);
  glVertex3f(getWidth(), getHeight(), 0);
  glVertex3f(0, getHeight(), 0);
  glEnd();

  // red square
  glColor4f(1, 0, 0, 1);
  glBegin(GL_QUADS);
  glVertex3f(getWidth() / 8, getHeight() / 3, 0);
  glVertex3f(getWidth() * 3 / 8, getHeight() / 3, 0);
  glVertex3f(getWidth() * 3 / 8, getHeight() * 2 / 3, 0);
  glVertex3f(getWidth() / 8, getHeight() * 2 / 3, 0);
  glEnd();

  // ------------- draw some 3D ----------------
  prepare3DViewport(getWidth() / 2, 0, getWidth(), getHeight());
  glLoadIdentity();

  glColor4f(0, 0, 1, 1);
  glTranslatef(0, 0, -5);
  glRotatef(50.0f, 0.0f, 1.0f, 0.0f);

  glColor4f(1, 0, 0, 1);
  for (int i = 0; i < 6; i++) {
    glBegin(GL_LINE_STRIP);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glEnd();
  }

  glFlush();
  SwapBuffers();*/
}

BEGIN_EVENT_TABLE(BasicGLPane, wxGLCanvas)
EVT_MOTION(BasicGLPane::mouseMoved)
EVT_LEFT_DOWN(BasicGLPane::mouseDown)
EVT_LEFT_UP(BasicGLPane::mouseReleased)
EVT_RIGHT_DOWN(BasicGLPane::rightClick)
EVT_LEAVE_WINDOW(BasicGLPane::mouseLeftWindow)
EVT_SIZE(BasicGLPane::resized)
EVT_KEY_DOWN(BasicGLPane::keyPressed)
EVT_KEY_UP(BasicGLPane::keyReleased)
EVT_MOUSEWHEEL(BasicGLPane::mouseWheelMoved)
EVT_PAINT(BasicGLPane::render)
END_EVENT_TABLE()