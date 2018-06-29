#pragma once

#include "Camera.h"
#include "Loader.h"
#include "Renderer.h"
#include "StaticShader.h"
#include "Entity.h"

class Scene {
public:
	Scene();
	~Scene();

	void render();

	//private:
	Loader loader;
	Renderer renderer;
	StaticShader shader;
	Entity entity;
	int c = 0;
};
