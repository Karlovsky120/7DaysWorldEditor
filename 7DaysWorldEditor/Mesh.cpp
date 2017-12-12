#include "Mesh.h"

GLuint Mesh::getVaoID() const {
  return vaoID;
}

int Mesh::getVertexCount() const {
  return vertexCount;
}

Mesh::Mesh(const GLuint vaoID, const int veertexCount) :
  vaoID(vaoID),
  vertexCount(vertexCount) {}

Mesh::~Mesh() {}
