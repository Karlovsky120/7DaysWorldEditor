#include "StaticShader.h"

#include "glm\glm.hpp"

StaticShader::StaticShader() : ShaderProgram(vertexShaderSource, fragmentShaderSource) {
    getAllUniformLocations();
}

StaticShader::~StaticShader() {}

void StaticShader::loadTransformationMatrix(glm::mat4x4 transformationMatrix) {
    ShaderProgram::loadMatrix4fUniform(tranformationMatrixLocation, transformationMatrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4x4 projectionMatrix) {
    ShaderProgram::loadMatrix4fUniform(projectionMatrixLocation, projectionMatrix);
}

void StaticShader::loadViewMatrix(glm::mat4x4 viewMatrix) {
    ShaderProgram::loadMatrix4fUniform(viewMatrixLocation, viewMatrix);
}

std::string StaticShader::vertexShaderSource = "vertexShader.vert";

std::string StaticShader::fragmentShaderSource = "fragmentShader.frag";

void StaticShader::bindAttributes() {
    ShaderProgram::bindAttribute(0, "position");
    ShaderProgram::bindAttribute(1, "textureCoords");
}

void StaticShader::getAllUniformLocations() {
    tranformationMatrixLocation = getUniformLocation("transformationMatrix");
    projectionMatrixLocation = getUniformLocation("projectionMatrix");
    viewMatrixLocation = getUniformLocation("viewMatrix");
}
