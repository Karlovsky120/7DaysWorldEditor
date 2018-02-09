#pragma once

#include "Mesh.h"
#include "Texture.h"

class TexturedMesh {
public:
  TexturedMesh(Mesh mesh, Texture texture);
  TexturedMesh();

  Texture &getTexture();
  Mesh &getMesh();

private:
  Texture texture;
  Mesh mesh;
};

