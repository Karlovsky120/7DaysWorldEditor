#pragma once

#include "GL\glew.h"

class Texture {
public:
  GLuint getID() const;

  Texture(GLuint textureID);
  ~Texture();

private:
  GLuint textureID;
};

