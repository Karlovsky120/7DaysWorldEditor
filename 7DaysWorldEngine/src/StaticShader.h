#pragma once

#include "ShaderProgram.h"

class StaticShader : public ShaderProgram {
public:
	StaticShader();
	virtual ~StaticShader();

	void loadTransformationMatrix(glm::mat4x4 transformationMatrix);
	void loadProjectionMatrix(glm::mat4x4 projectionMatrix);
	void loadViewMatrix(glm::mat4x4 viewMatrix);

protected:
	void bindAttributes();
	void getAllUniformLocations();

	static std::string vertexShaderSource;
	static std::string fragmentShaderSource;

public:
	GLuint tranformationMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;
};
