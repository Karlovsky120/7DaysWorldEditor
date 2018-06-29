#include "Scene.h"

#include "Loader.h"

#include "GL\glew.h"

Scene::Scene() {
	float vertices[96] = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f

	};

	/*static GLfloat vertices[] = {
		// front
		-1.0, -1.0,  1.0,
		1.0, -1.0,  1.0,
		1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0,
	};*/

	int indices[36] = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22

	};

	/**static int indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// top
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 0, 3,
		3, 7, 4,
		// left
		4, 5, 1,
		1, 0, 4,
		// right
		3, 2, 6,
		6, 7, 3,
	};*/

	static float textureCoords[] = {
	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0
	};

	Loader loader = Loader();

	Transformation cameraTransformation = Transformation();
	Camera camera = Camera(cameraTransformation, 90.0f, 16.0f / 9.0f, 0.00001f, 10000.0f);

	renderer = Renderer(camera);
	shader = StaticShader();

	Mesh mesh;

	loader.loadToVAO(mesh, vertices, sizeof(vertices), indices, sizeof(indices), textureCoords, sizeof(textureCoords));
	Texture modelTexture = Texture(loader.loadTexture("texture"));
	TexturedMesh texturedMesh = TexturedMesh(mesh, modelTexture);

	Transformation entityTransformation = Transformation(glm::vec3(0.0f, 0.0f, -20.5f));//, glm::vec3(0.0f), glm::vec3(1.0f));
	entity = Entity(texturedMesh, entityTransformation);
}

Scene::~Scene() {}

void Scene::render() {
	renderer.prepare();
	shader.start();

	for (int i = -5; i < 5; i += 2) {
		for (int j = -5; j < 5; j += 2) {
			for (int k = -5; k < 5; k += 2) {
				entity.getEntityTransformation().setPosition(glm::vec3(i, j, k));
				renderer.render(entity, shader);
			}
		}
	}

	/*renderer.render(entity, shader);
	entity.getEntityTransformation().setPosition(glm::vec3(glm::sin(p)*6, glm::cos(p)*5, glm::sin(p/100)));
	p += 0.1;*/

	shader.stop();
}
