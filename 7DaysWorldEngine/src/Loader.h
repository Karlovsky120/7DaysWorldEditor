#pragma once

#include <GL\glew.h>

#include <string>
#include <vector>
#include <map>

class Mesh;

class Loader {
public:
    Loader();
    ~Loader();

    void loadToVAO(Mesh &mesh, const GLfloat vertices[], const int vertexCount, const int indices[], const int indexCount, const float textureCoords[], const int textureCordsCount);
    GLuint loadTexture(std::string textureName);

private:
    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;
    std::map<std::string, GLuint> textures;

    bool defaultTextureGenerated = false;

    unsigned char defaultTexture[256 * 256 * 4];

    GLuint createVAO();
    GLuint createVBO();
    void storeDataInAttributeList(const GLuint attributeNumber, const GLuint coordinateSize, const GLfloat data[], const GLsizeiptr dataCount);
    void bindIndicesBuffer(const int indices[], const int indexCount);

    void generateDefaultTexture();
    void setPixelForTexture(unsigned char pixelLocation[], unsigned char r, unsigned char g, unsigned char b, unsigned char a);
};
