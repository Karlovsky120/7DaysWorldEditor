#pragma once

#include <string>

#include "GL\glew.h"
#include "glm\fwd.hpp"

class ShaderProgram {
public:
  void start();
  void stop();

  ShaderProgram(std::string vertexShader, std::string fragmentShader);
  ~ShaderProgram();

protected:
  virtual void bindAttributes() = 0;
  virtual void getAllUniformLocations() = 0;

  void bindAttribute(GLuint attribute, const char* attributeName);
  GLuint getUniformLocation(const char* uniformName);
  void loadFloatUniform(GLuint location, GLfloat value);
  void loadVector3fUniform(GLuint location, glm::vec3 value);
  void loadBooleanUniform(GLuint location, GLboolean value);
  void loadMatrix4fUniform(GLuint location, glm::mat4x4 &value);

private:
  GLuint programID;
  GLuint vertexShaderID;
  GLuint fragmentShaderID;

  static GLuint loadShader(std::string shaderFile, GLenum type);
};

