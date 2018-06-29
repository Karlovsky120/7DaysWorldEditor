#pragma once

#include "TexturedMesh.h"
#include "Transformation.h"

#include "glm\fwd.hpp"

class Entity {
public:
	Entity(TexturedMesh &texturedModel, Transformation &transformation);
	Entity();

	glm::mat4x4 getTransformationMatrix() const;

	Transformation &getEntityTransformation();
	TexturedMesh &getTexturedMesh();

private:
	TexturedMesh texturedMesh;
	Transformation transformation;
};
