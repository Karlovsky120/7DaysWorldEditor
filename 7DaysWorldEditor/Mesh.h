#pragma once

#include "GL\glew.h"

class Mesh {
public:
  GLuint getVaoID() const;
  int getVertexCount() const;

  Mesh(const GLuint vaoID, const int vertexCount);
  ~Mesh();

private:
  GLuint vaoID;
  int vertexCount;
};

