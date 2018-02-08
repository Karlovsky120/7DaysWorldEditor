#pragma once

#include "GL\glew.h"

class Texture {
public:
  Texture(GLuint textureID);
  Texture();
  ~Texture();

  GLuint getID() const;

private:
  GLuint textureID;
};

