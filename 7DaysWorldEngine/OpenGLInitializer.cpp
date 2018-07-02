#include "OpenGLInitializer.h"

#include "GL\glew.h"

bool OpenGLInitializer::InitializeOpenGL(std::string *error) {
	GLenum err = glewInit();
	if (err != GL_NO_ERROR) {
		char *cError = (char *)glewGetErrorString(err);
		*error = std::string(cError);
		return false;
	}

	return true;
}

OpenGLInitializer::OpenGLInitializer() {}
OpenGLInitializer::~OpenGLInitializer() {}
