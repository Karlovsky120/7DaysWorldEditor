#pragma once

#include "glm\glm.hpp"
#include "glm\gtx\quaternion.hpp"

class Camera {
public:
	Camera(glm::vec3 position = glm::vec3(0.0f),
		   glm::quat rotation = glm::angleAxis(0.0f, glm::vec3(0.0f, 0.0f, 1.0f)),
		   float FOV = 90.0f,
		   float aspectRatio = 16/9,
		   float nearPlane = 0.001f,
		   float farPlane = 1000.0f);

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
