#version 330 core

layout (location = 0) in vec3 a_Position;

out vec4 out_Color;
uniform mat4 u_Transform;
uniform vec4 u_Color;

void main(void) { 
    gl_Position = model * vec4(aPosition, 1.0);
    out_Color = u_Color;
}
