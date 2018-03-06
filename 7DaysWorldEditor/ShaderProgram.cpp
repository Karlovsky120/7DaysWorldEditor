#include "ShaderProgram.h"

#include "GL\glew.h"
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "wx\log.h"

#include <fstream>

GLuint ShaderProgram::loadShader(std::string shaderFile, GLenum type) {
	std::ifstream in(".\\resources\\shaders\\" + shaderFile, std::ios::in);
	std::string src = "";
	std::string line = "";

	while (std::getline(in, line)) {
		src += line + "\n";
	}

	GLuint shader = glCreateShader(type);

	const char *source = src.c_str();
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::string error = "GLEW Error: " + std::string(infoLog);
		wxLog(wxT(error));
	}

	return shader;
}

void ShaderProgram::start() {
	glUseProgram(programID);
}

void ShaderProgram::stop() {
	glUseProgram(0);
}

void ShaderProgram::bindAttribute(GLuint attributeIndex, const char *variableName) {
	glBindAttribLocation(programID, attributeIndex, variableName);
}

GLuint ShaderProgram::getUniformLocation(const char *uniformName) {
	return glGetUniformLocation(programID, uniformName);
}

void ShaderProgram::loadFloatUniform(GLuint location, GLfloat value) {
	glUniform1f(location, value);
}

void ShaderProgram::loadVector3fUniform(GLuint location, glm::vec3 value) {
	glUniform3f(location, value.x, value.y, value.z);
}

void ShaderProgram::loadBooleanUniform(GLuint location, GLboolean value) {
	glUniform1i(location, (GLint)value);
}

void ShaderProgram::loadMatrix4fUniform(GLuint location, glm::mat4x4 &value) {
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
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
