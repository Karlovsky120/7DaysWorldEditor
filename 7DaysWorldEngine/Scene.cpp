#include "Scene.h"

#include "Loader.h"

#include "GL\glew.h"

Scene::Scene() {

	GLfloat vertices[] = {
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

	static float textureCoords[48] = {
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

	loader = Loader();

	Camera camera = Camera(glm::vec3(0.0f), glm::angleAxis(0.0f, glm::vec3(0.0f, 0.0f, 1.0f)), 70.0f, 16.0f / 9.0f, 0.00001f, 10000.0f);

	renderer = Renderer(camera);

	Mesh mesh;

	loader.loadToVAO(mesh, vertices, sizeof(vertices) / (3 * sizeof(vertices[0])),
                           indices, sizeof(indices) / sizeof(indices[0]),
		                   textureCoords, sizeof(textureCoords) / (2 * sizeof(textureCoords[0])));

	Texture texture = Texture(loader.loadTexture("texture"));
	TexturedMesh texturedMesh = TexturedMesh(mesh, texture);

	Transformation entityTransformation = Transformation(glm::vec3(0.0f, 0.0f, -200.5f));
	entity = Entity(texturedMesh, entityTransformation);
}

Scene::~Scene() {}

void Scene::render() {
	renderer.prepare();
	shader.start();

	for (float i = -10; i < 10; i += 1.8) {
		for (float j = -10; j < 10; j += 1.8) {
			for (float k = -100; k < -1; k += 1.8) {
				entity.getEntityTransformation().setPosition(glm::vec3(i + 2/i*glm::sin(i*k*c / 1000)/10, j + 2/j*glm::sin(j*j*c / 100)/10, k + 2/k*glm::sin(k*i*c / 10)/10));
				renderer.render(entity, shader);
				++c;
			}
		}
	}
	shader.stop();
}
