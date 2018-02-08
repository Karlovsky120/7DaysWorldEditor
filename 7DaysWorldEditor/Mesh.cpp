#include "Mesh.h"

Mesh::Mesh(const GLuint vaoID, const int vertexCount, const int indexCount) :
  vaoID(vaoID),
  vertexCount(vertexCount),
  indexCount(indexCount) {}

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