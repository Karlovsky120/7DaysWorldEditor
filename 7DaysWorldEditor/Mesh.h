#pragma once

#include "GL\glew.h"

class Mesh {
public:
	Mesh(const GLuint vaoID, const int vertexCount, const int indexCount);
	Mesh();
	~Mesh();

	GLuint getVaoID() const;
	int getVertexCount() const;
	int getIndexCount() const;

private:
	GLuint vaoID;
	int vertexCount;
	int indexCount;
};
