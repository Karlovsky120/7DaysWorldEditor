#include "Loader.h"

#include "Mesh.h"

#undef _UNICODE //Si if necessary and remove if not.
#include "IL\il.h"
#include "IL\ilu.h"
#include "IL\ilut.h"


Loader::Loader() {
    ilInit();
    iluInit();
    ilutInit();
}

Loader::~Loader() {

    for (auto it = vaos.begin(); it != vaos.end(); it++) {
        glDeleteVertexArrays(1, &(*it));
    }

    for (auto it = vbos.begin(); it != vbos.end(); it++) {
        glDeleteBuffers(1, &(*it));
    }

    for (auto it = textures.begin(); it != textures.end(); it++) {
        glDeleteTextures(1, &(it->second));
    }
}

void Loader::loadToVAO(Mesh &mesh, const GLfloat vertices[], const int vertexCount, const int indices[], const int indexCount, const float textureCoords[], const int textureCoordsCount) {
    GLuint vaoID = createVAO();
    glBindVertexArray(vaoID);
    bindIndicesBuffer(indices, indexCount);
    storeDataInAttributeList(0, 3, vertices, vertexCount);
    storeDataInAttributeList(1, 2, textureCoords, textureCoordsCount);
    glBindVertexArray(0);

    mesh = Mesh(vaoID, vertexCount, indexCount);
}

//future work
//better handle various glTexImage2D parameters
GLuint Loader::loadTexture(std::string textureName) {

    //check if texture is already loaded
    auto foundTextureIt = textures.find(textureName);
    if (foundTextureIt != textures.end()) {
        //texture allready loaded
        return foundTextureIt->second;
    }

    std::string path = "Resources\\Textures\\" + textureName;
    ilLoadImage(path.c_str());

    int imageWidth = ilGetInteger(IL_IMAGE_WIDTH);
    int imageHeight = ilGetInteger(IL_IMAGE_HEIGHT);
    int imageComponents = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);

    unsigned char *image = ilGetData();

    ILenum Error;
    while ((Error = ilGetError()) != IL_NO_ERROR) {
        std::string errorMessage = iluErrorString(Error);
        //printf("%d: %s/n", Error, iluErrorString(Error));
        if (!defaultTextureGenerated) {
            generateDefaultTexture();
        }
        image = defaultTexture;
        imageWidth = 256;
        imageHeight = 256;
        imageComponents = 4;
    }

    GLuint textureID = 0;
    glGenTextures(1, &textureID);
    textures.insert(std::pair<std::string, GLuint>(textureName, textureID));

    glBindTexture(GL_TEXTURE_2D, textureID);

    if (imageComponents == 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    } else if (imageComponents == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}

GLuint Loader::createVAO() {
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    vaos.push_back(vaoID);

    return vaoID;
}

GLuint Loader::createVBO() {
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);

    return vboID;
}

void Loader::storeDataInAttributeList(const GLuint attributeNumber, const GLuint coordinateSize, const GLfloat data[], const GLsizeiptr dataCount) {
    GLuint vboID = createVBO();

    glBindBuffer(GL_ARRAY_BUFFER, vboID);

    glBufferData(GL_ARRAY_BUFFER, dataCount * sizeof(GLfloat) * coordinateSize, data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(attributeNumber);
    glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::bindIndicesBuffer(const int indices[], const int indexCount) {
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(int), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Loader::generateDefaultTexture() {
    unsigned int counter = 0;

    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            if ((i / 32) % 2 == (j / 32) % 2) {
                setPixelForTexture(&defaultTexture[counter], (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0);
            } else {
                setPixelForTexture(&defaultTexture[counter], (unsigned char)255, (unsigned char)0, (unsigned char)128, (unsigned char)0);
            }

            counter += 4;
        }
    }
}

void inline Loader::setPixelForTexture(unsigned char pixelLocation[], unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    pixelLocation[0] = r;
    pixelLocation[1] = g;
    pixelLocation[2] = b;
    pixelLocation[3] = a;
}
