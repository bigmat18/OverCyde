#version 330 core 
layout (location = 0) in vec3 aPosition; 

out vec3 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main(void) { 
    vec4 pos = projection * view * model * vec4(aPosition, 1.0);
    gl_Position = pos.xyzw;
    TexCoords = aPosition;
}