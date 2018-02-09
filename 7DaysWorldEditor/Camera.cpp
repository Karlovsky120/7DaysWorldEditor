#include "Camera.h"

#include "glm\gtx\transform.hpp"


Camera::Camera(Transformation cameraTransformation, float FOV, float aspectRatio, float nearPlane, float farPlane) :
  cameraTransformation(cameraTransformation),
  projectionMatrix(glm::perspective(FOV, aspectRatio, nearPlane, farPlane)) {}

Camera::Camera() {}

Transformation *Camera::getCameraTransformation() {
  return &cameraTransformation;
}

glm::mat4x4 Camera::getViewMatrix() {
  glm::mat4x4 viewMatrix = glm::mat4_cast(cameraTransformation.getRotation());
  viewMatrix = glm::translate(viewMatrix, cameraTransformation.getPosition());

  return viewMatrix;
}

glm::mat4x4 &Camera::getProjectionMatrix() {
  return projectionMatrix;
}
