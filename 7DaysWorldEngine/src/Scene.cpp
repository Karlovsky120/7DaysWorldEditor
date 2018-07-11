#include "Scene.h"

#include "AssetLoader.h"
#include "Loader.h"

#include "binaryIO/BinaryFileReader.h"
#include "GL\glew.h"


Scene::Scene() {

    AssetLoader assetLoader;

    std::string address = "C:\\Programs\\Steam\\steamapps\\common\\7 Days To Die\\7DaysToDie_Data\\resources.assets";

    BinaryFileReader reader(address);
    assetLoader.extractAssetInfo(reader);
    assetLoader.loadRelevantAssets(reader);

    int a = 4;

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

    Camera camera = Camera(glm::vec3(0.0f), glm::angleAxis(0.0f, glm::vec3(0.0f, 0.0f, 1.0f)), glm::radians(90.0f), 16.0f / 9.0f, 0.01f, 1000.0f);


    renderer = Renderer(camera);

    Mesh mesh;

    loader.loadToVAO(mesh, vertices, sizeof(vertices) / (3 * sizeof(vertices[0])),
                     indices, sizeof(indices) / sizeof(indices[0]),
                     textureCoords, sizeof(textureCoords) / (2 * sizeof(textureCoords[0])));

    Texture texture = Texture(loader.loadTexture("testing.png"));
    TexturedMesh texturedMesh = TexturedMesh(mesh, texture);

    Transformation entityTransformation = Transformation(glm::vec3(0.0f, 0.0f, -200.5f));
    entity = Entity(texturedMesh, entityTransformation);
}

Scene::~Scene() {}

void Scene::render() {
    renderer.prepare();
    shader.start();

    for (float i = -5; i < 5; i += 2) {
        for (float j = -5; j < 5; j += 2) {
            for (float k = -50; k < -1; k += 2) {
                entity.getEntityTransformation().setPosition(glm::vec3(i + glm::sin(c / 100) / 50, j + glm::sin(c / 10000) / 50, k + glm::sin(c / 10) / 50));
                renderer.render(entity, shader);
                c += (float)0.1;
            }
        }
    }
    shader.stop();
}
