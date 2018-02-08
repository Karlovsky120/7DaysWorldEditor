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

// some useful events to use
void OpenGLCanvas::mouseMoved(wxMouseEvent& event) {}
void OpenGLCanvas::mouseDown(wxMouseEvent& event) {}
void OpenGLCanvas::mouseWheelMoved(wxMouseEvent& event) {}
void OpenGLCanvas::mouseReleased(wxMouseEvent& event) {}
void OpenGLCanvas::rightClick(wxMouseEvent& event) {}
void OpenGLCanvas::mouseLeftWindow(wxMouseEvent& event) {}
void OpenGLCanvas::keyPressed(wxKeyEvent& event) {}
void OpenGLCanvas::keyReleased(wxKeyEvent& event) {}

// Vertices and faces of a simple cube to demonstrate 3D render
// source: http://www.opengl.org/resources/code/samples/glut_examples/examples/cube.c
GLfloat v[8][3];
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3},{3, 2, 6, 7},{7, 6, 5, 4},
  {4, 5, 1, 0},{5, 6, 2, 1},{7, 4, 0, 3}};



OpenGLCanvas::OpenGLCanvas(wxFrame* parent, int* args) :
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
    exit(4001);
  }

  // To avoid flashing on MSW
  SetBackgroundStyle(wxBG_STYLE_CUSTOM);

  scene = std::make_unique<Scene>();
}

OpenGLCanvas::~OpenGLCanvas() {
  delete m_context;
}

void OpenGLCanvas::resized(wxSizeEvent& evt) {
  //wxGLCanvas::OnSize(evt);

  const wxSize ClientSize = GetClientSize();
  glViewport(0, 0, ClientSize.x, ClientSize.y);

  Refresh();
}


int OpenGLCanvas::getWidth() const {
  return GetSize().x;
}

int OpenGLCanvas::getHeight() const {
  return GetSize().y;
}

void OpenGLCanvas::applyViewportTransformation(Transformation *cameraTransformation) {
  wxSize oldSize = canvasSize;
  canvasSize = GetClientSize();

  glm::vec3 scale = glm::vec3(oldSize.x / canvasSize.x, oldSize.y / canvasSize.x, 1.0f);
  cameraTransformation->scaleObject(scale);
}


void OpenGLCanvas::render(wxPaintEvent& evt) {
  if (!IsShown()) return;

  wxGLCanvas::SetCurrent(*m_context);
  wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event


  /*const wxSize ClientSize = GetClientSize();
  glViewport(0, 0, ClientSize.x, ClientSize.y);*/

  //applyViewportTransformation(camera.getCameraTransformation());


  scene->render();


  /*for (int i = -5; i < 5; i += 2) {
    for (int j = -5; j < 5; j += 2) {
      for (int k = -5; k < 5; k += 2) {*/
        //entity.getEntityTransformation().setPosition(glm::vec3(i, j, k));
  //scene->renderer.render(scene->entity, scene->shader);
      /*}
    }
  }*/

  //shader.stop();

  




  /*glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

  /*GLfloat vertices[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f
  };*/

  /*GLuint VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  GLuint VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), vertices, GL_STATIC_DRAW);*/



  /*unsigned int vertexShader;
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

  char *fragmentShaderSource = "#version 330 core    \nout vec4 FragColor;    void main() {    FragColor = vec4(1.0f, 0.0f, 0.5f, 1.0f);  }";

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
  glDeleteShader(fragmentShader);*/

  //glDrawArrays(GL_TRIANGLES, 0, 3);

  SwapBuffers();
}

BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
EVT_MOTION(OpenGLCanvas::mouseMoved)
EVT_LEFT_DOWN(OpenGLCanvas::mouseDown)
EVT_LEFT_UP(OpenGLCanvas::mouseReleased)
EVT_RIGHT_DOWN(OpenGLCanvas::rightClick)
EVT_LEAVE_WINDOW(OpenGLCanvas::mouseLeftWindow)
EVT_SIZE(OpenGLCanvas::resized)
EVT_KEY_DOWN(OpenGLCanvas::keyPressed)
EVT_KEY_UP(OpenGLCanvas::keyReleased)
EVT_MOUSEWHEEL(OpenGLCanvas::mouseWheelMoved)
EVT_PAINT(OpenGLCanvas::render)
END_EVENT_TABLE()