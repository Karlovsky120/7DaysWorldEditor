#pragma once

#include "Transformation.h"

class Camera {
public:
	Camera(glm::vec3 position, glm::quat rotation, float FOV, float aspectRatio, float nearPlane, float farPlane);
	Camera::Camera();

	glm::mat4x4 getViewMatrix();
	glm::mat4x4 &getProjectionMatrix();

	glm::vec3 getPosition() const;
	glm::quat getRotation() const;

	void setPosition(const glm::vec3 &position);
	void setRotation(const glm::quat &rotation);

	void translate(const glm::vec3 &translation);

	void rotateFromLeft(const glm::quat &rotation);
	void rotateFromLeft(const float angle, const glm::vec3 &axis);
	void rotateFromRight(const glm::quat &rotation);
	void rotateFromRight(const float angle, const glm::vec3 &axis);

	glm::vec3 getForwardUnitVector() const;
	glm::vec3 getUpUnitVector() const;
	glm::vec3 getLeftUnitVector() const;

private:
	glm::mat4x4 projectionMatrix;

	glm::vec3 position;
	glm::quat rotation;
};
