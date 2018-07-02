#include "TexturedMesh.h"

TexturedMesh::TexturedMesh(Mesh mesh, Texture texture) :
	mesh(mesh),
	texture(texture) {}

TexturedMesh::TexturedMesh() {}

Texture &TexturedMesh::getTexture() {
	return texture;
}

Mesh &TexturedMesh::getMesh() {
	return mesh;
}
