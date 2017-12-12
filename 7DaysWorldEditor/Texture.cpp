#include "Texture.h"

GLuint Texture::getID() const {
  return textureID;
}

Texture::Texture(GLuint textureID) : 
  textureID(textureID) {}

Texture::~Texture() {}
