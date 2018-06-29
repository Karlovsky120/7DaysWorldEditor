#include "Camera.h"

#include "glm\gtx\transform.hpp"
#include "glm\gtx\quaternion.hpp"

Camera::Camera(glm::vec3 position, glm::quat rotation, float FOV, float aspectRatio, float nearPlane, float farPlane) :
	projectionMatrix(glm::perspective(FOV, aspectRatio, nearPlane, farPlane)) {}

Camera::Camera() {}

glm::mat4x4 Camera::getViewMatrix() {
	glm::mat4x4 viewMatrix = glm::mat4_cast(getRotation());
	viewMatrix = glm::translate(viewMatrix, getPosition());

	return viewMatrix;
}

glm::mat4x4 &Camera::getProjectionMatrix() {
	return projectionMatrix;
}

glm::vec3 Camera::getPosition() const {
	return this->position;
}
glm::quat Camera::getRotation() const {
	return this->rotation;
}

void Camera::setPosition(const glm::vec3 &position) {
	this->position = position;
}

void Camera::setRotation(const glm::quat &rotation) {
	this->rotation = rotation;
}

void Camera::translate(const glm::vec3 &translation) {
	this->position -= translation;
}

void Camera::rotateFromLeft(const glm::quat &rotation) {
	this->rotation = glm::inverse(rotation) * this->rotation;
}

void Camera::rotateFromLeft(const float angle, const glm::vec3 &axis) {
	rotateFromLeft(glm::angleAxis(glm::radians(angle), axis));
}

void Camera::rotateFromRight(const glm::quat &rotation) {
	this->rotation = this->rotation * glm::inverse(rotation);
}

void Camera::rotateFromRight(const float angle, const glm::vec3 &axis) {
	rotateFromRight(glm::angleAxis(glm::radians(angle), axis));
}

glm::vec3 Camera::getForwardUnitVector() const {
	return glm::rotate(glm::inverse(rotation), glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::vec3 Camera::getUpUnitVector() const {
	return glm::rotate(glm::inverse(rotation), glm::vec3(0.0f, -1.0f, 0.0f));
}

glm::vec3 Camera::getLeftUnitVector() const {
	return glm::rotate(glm::inverse(rotation), glm::vec3(-1.0f, 0.0f, 0.0f));
}
