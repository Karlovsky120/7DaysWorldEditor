#pragma once

#include "Transformation.h"

class Camera {
public:
	Camera(Transformation cameraTransformation, float FOV, float aspectRatio, float nearPlane, float farPlane);
	Camera::Camera();

	Transformation *getCameraTransformation();
	glm::mat4x4 getViewMatrix();
	glm::mat4x4 &getProjectionMatrix();

private:
	Transformation cameraTransformation;
	glm::mat4x4 projectionMatrix;
};
