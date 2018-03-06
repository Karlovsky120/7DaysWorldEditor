#include "Entity.h"

#include "glm\gtx\transform.hpp"

Entity::Entity(TexturedMesh &texturedMesh, Transformation &transformation) :
	texturedMesh(texturedMesh),
	transformation(transformation) {}

Entity::Entity() {};

glm::mat4x4 Entity::getTransformationMatrix() const {
	glm::mat4x4 matrix = glm::mat4x4();
	matrix = glm::translate(matrix, transformation.getPosition());
	matrix *= glm::mat4_cast(glm::quat(transformation.getRotation()));
	matrix = glm::scale(matrix, transformation.getScale());

	return matrix;
}

Transformation &Entity::getEntityTransformation() {
	return transformation;
}

TexturedMesh &Entity::getTexturedMesh() {
	return texturedMesh;
}
