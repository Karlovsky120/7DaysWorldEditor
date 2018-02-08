#include "TexturedMesh.h"

TexturedMesh::TexturedMesh(Mesh &mesh, Texture &texture) :
  mesh(mesh),
  texture(texture) {}

TexturedMesh::TexturedMesh() {}

Mesh &TexturedMesh::getMesh() {
  return mesh;
}

Texture &TexturedMesh::getTexture() {
  return texture;
}
