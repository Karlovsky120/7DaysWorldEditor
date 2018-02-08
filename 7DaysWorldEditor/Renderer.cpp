#include "Renderer.h"

#include "Entity.h"
#include "StaticShader.h"
#include "TexturedMesh.h"

#include "GL\glew.h"


Renderer::Renderer(Camera &camera) :
  camera(camera) {}

Renderer::Renderer() {}

void Renderer::prepare() {
  glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

}

void Renderer::render(Entity &entity, StaticShader &shader) {
  TexturedMesh texturedMesh = entity.getTexturedMesh();
  Mesh mesh = texturedMesh.getMesh();

  glBindVertexArray(mesh.getVaoID());
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  shader.loadProjectionMatrix(camera.getProjectionMatrix());
  shader.loadViewMatrix(camera.getViewMatrix());
  shader.loadTransformationMatrix(entity.getTransformationMatrix());

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texturedMesh.getTexture().getID());
  glDrawElements(GL_TRIANGLES, mesh.getIndexCount(), GL_UNSIGNED_INT, (void*)0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}