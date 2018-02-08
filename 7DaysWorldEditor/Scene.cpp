#include "Scene.h"

#include "Loader.h"

#include "GL\glew.h"

Scene::Scene() {
  static GLfloat vertices[] = {
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
  };

  static int indices[] = {
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
  };

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
  camera = Camera(cameraTransformation, 90.0f, 16.0f / 9.0f, 0.00001f, 1000.0f);

  renderer = Renderer(camera);
  shader = StaticShader();

  Mesh mesh = loader.loadToVAO(vertices, sizeof(vertices), indices, sizeof(indices), textureCoords, sizeof(textureCoords));
  Texture modelTexture = Texture(loader.loadTexture("texture"));
  TexturedMesh texturedMesh = TexturedMesh(mesh, modelTexture);

  Transformation entityTransformation = Transformation(glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f), glm::vec3(1.0f));
  entity = Entity(texturedMesh, entityTransformation);
}


Scene::~Scene() {}


void Scene::render() {
  renderer.prepare();
  shader.start();

  renderer.render(entity, shader);
}
