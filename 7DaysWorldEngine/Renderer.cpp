#include "Renderer.h"

#include "Entity.h"
#include "StaticShader.h"
#include "TexturedMesh.h"

#include "GL\glew.h"

#include <math.h>


#include <glm/gtc/matrix_transform.hpp>


Renderer::Renderer(Camera camera) :
	camera(camera) {}

Renderer::Renderer() {}

void Renderer::prepare() {
	glClearColor(std::sin(c / 1000), std::sin(c / 100), std::sin(c / 10), 1.0f);
	c += 1.0f;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Renderer::render(Entity &entity, StaticShader &shader) {
	TexturedMesh texturedMesh = entity.getTexturedMesh();
	Mesh mesh = texturedMesh.getMesh();

	glBindVertexArray(mesh.getVaoID());

	shader.loadViewMatrix(camera.getViewMatrix());
	shader.loadProjectionMatrix(camera.getProjectionMatrix());
	/*
	shader.loadProjectionMatrix(glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f));
	shader.loadViewMatrix(glm::lookAt(
				glm::vec3(3, 3, -3),
				glm::vec3(0, 0, 0), 
				glm::vec3(0, 1, 0)));
	*/
	
	shader.loadTransformationMatrix(entity.getTransformationMatrix());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturedMesh.getTexture().getID());

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 1);

	glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
}
