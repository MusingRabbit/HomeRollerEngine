#version 430

layout (location=0) in vec3 position;
layout (location=1) in vec3 colour;

out vec4 vertColour;

uniform mat4 transform;

void main(){
    vertColour = vec4(clamp(position,0.0,1.0),1.0f);
    gl_Position =  vec4(position,1.0) * transform;
}