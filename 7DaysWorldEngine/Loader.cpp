#include "Loader.h"

#include "Mesh.h"

void Loader::loadToVAO(Mesh &mesh, const GLfloat vertices[], const int vertexCount, const int indices[], const int indexCount, const float textureCoords[], const int textureCoordsCount) {
	GLuint vaoID = createVAO();
	glBindVertexArray(vaoID);
	bindIndicesBuffer(indices, indexCount);
	storeDataInAttributeList(0, 3, vertices, vertexCount);
	storeDataInAttributeList(1, 2, textureCoords, textureCoordsCount);
	glBindVertexArray(0);

	mesh = Mesh(vaoID, vertexCount, indexCount);
}

void Loader::generateDefaultTexture() {
	unsigned int counter = 0;

	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; ++j) {
			if ((i / 32) % 2 == (j / 32) % 2) {
				setPixelForTexture(&defaultTexture[counter], (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)0);
			}

			else {
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

//EDIT TO NOT GENERATE NEW ID FOR MULTIPLE DEFAULT TEXTURES
GLuint Loader::loadTexture(std::string textureName) {
	int width;
	int height;
	int comp;

	/*std::string path = "Resources\\Textures\\" + textureName + ".png";*/

	unsigned char *image;// = stbi_load(path.c_str(), &width, &height, &comp, STBI_rgb_alpha);*/

	bool textureLoadFailed = false;

	//if (image == nullptr) {
	textureLoadFailed = true;
	if (!defaultTextureGenerated) {
		generateDefaultTexture();
	}
	image = defaultTexture;
	width = 256;
	height = 256;
	comp = 4;
	//}

	GLuint textureID = 0;
	glGenTextures(1, &textureID);
	textures.push_back(textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);

	/*if (!textureLoadFailed) {
	stbi_image_free(image);
	}*/

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

Loader::~Loader() {
	for (GLuint i = 0; i < vaos.size(); ++i) {
		glDeleteVertexArrays(1, &vaos.back());
		vaos.pop_back();
	}

	for (GLuint i = 0; i < vbos.size(); ++i) {
		glDeleteBuffers(1, &vbos.back());
		vbos.pop_back();
	}

	for (GLuint i = 0; i < textures.size(); ++i) {
		glDeleteTextures(1, &textures.back());
		textures.pop_back();
	}
}