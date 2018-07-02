#pragma once

#include "Camera.h"

class Entity;
class StaticShader;

class Renderer {
public:
	Renderer(Camera camera);
	Renderer();

	void prepare();
	void render(Entity &entity, StaticShader &shader);

private:
	Camera camera;
	float c = 100;
};
