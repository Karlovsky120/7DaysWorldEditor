#pragma once

#include <string>

#include "GL\glew.h"

class ShaderProgram {
public:
  void start();
  void stop();

  ShaderProgram(std::string vertexShader, std::string fragmentShader);
  ~ShaderProgram();

private:
  GLuint programID;
  GLuint vertexShaderID;
  GLuint fragmentShaderID;

  static GLuint loadShader(std::string shaderFile, GLenum type);
};

