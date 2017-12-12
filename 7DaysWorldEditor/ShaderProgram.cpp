#include "ShaderProgram.h"

#include "wxWidgets.h"

#include <fstream>

GLuint ShaderProgram::loadShader(std::string shaderFile, GLenum type) {
  std::ifstream in("resources\\shaders\\" + shaderFile);
  std::string src = "";
  std::string line = "";

  while (std::getline(in, line)) {
    src += line + "\n";
  }

  GLuint shader = glCreateShader(type);

  const char *source = src.c_str();
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);

  return shader;
}

void ShaderProgram::start() {
  glUseProgram(programID);
}

void ShaderProgram::stop() {
  glUseProgram(0);
}


ShaderProgram::ShaderProgram(std::string vertexShader, std::string fragmentShader) {
  vertexShaderID = loadShader(vertexShader, GL_VERTEX_SHADER);
  fragmentShaderID = loadShader(fragmentShader, GL_FRAGMENT_SHADER);

  programID = glCreateProgram();

  glAttachShader(programID, vertexShaderID);
  glAttachShader(programID, fragmentShaderID);

  glLinkProgram(programID);

  GLint linked;
  glGetProgramiv(programID, GL_LINK_STATUS, &linked);

  if (!linked) {
    int infoLogLength;
    int charsWritten;
    char *infoLog;

    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

    wxLogError(wxT("Shader Error!"));

    if (infoLogLength > 0) {
      infoLog = (char *)malloc(infoLogLength);
      glGetProgramInfoLog(programID, infoLogLength, &charsWritten, infoLog);

      wxLogError(infoLog);
      free(infoLog);
    }
  }
}

ShaderProgram::~ShaderProgram() {
  stop();

  glDetachShader(programID, vertexShaderID);
  glDetachShader(programID, fragmentShaderID);

  glDeleteShader(vertexShaderID);
  glDeleteShader(fragmentShaderID);

  glDeleteProgram(programID);
}
