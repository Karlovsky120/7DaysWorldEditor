#version 400 core

//in vec2 passedTextureCoords;
out vec4 outColour;

//uniform sampler2D textureSampler;

void main(){
    outColour = vec4(1.0f, 0.8f, 0.4f, 1.0f); //texture(textureSampler, passedTextureCoords);
}