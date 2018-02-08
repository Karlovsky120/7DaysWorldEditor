#include "Texture.h"

Texture::Texture(GLuint textureID) :
  textureID(textureID) {}
Texture::Texture() {}

Texture::~Texture() {}

GLuint Texture::getID() const {
  return textureID;
}
