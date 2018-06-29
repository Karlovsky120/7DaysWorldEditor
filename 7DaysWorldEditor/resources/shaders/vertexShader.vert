#version 400 core

layout(location = 0) in vec3 position;
in vec2 textureCoords;
out vec2 passedTextureCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 transformationMatrix;

void main(){
    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0);
    passedTextureCoords = textureCoords;
}