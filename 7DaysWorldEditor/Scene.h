#pragma once

#include "Camera.h"
#include "Renderer.h"
#include "StaticShader.h"
#include "Entity.h"

class Scene {
public:
	Scene();
	~Scene();

	void render();

	//private:
	Renderer renderer;
	StaticShader shader;
	Entity entity;
	int p = 0;
};
