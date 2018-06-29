#include "Mesh.h"

Mesh::Mesh(const GLuint vaoID, const int vertexCount, const int iIndexCount) :
	vaoID(vaoID),
	vertexCount(vertexCount),
	indexCount(iIndexCount) {}

Mesh::Mesh() {}
Mesh::~Mesh() {}

GLuint Mesh::getVaoID() const {
	return vaoID;
}

int Mesh::getVertexCount() const {
	return vertexCount;
}

int Mesh::getIndexCount() const {
	return indexCount;
}
