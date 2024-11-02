#version 330 core

layout (location = 0) in vec3 a_Position;

out vec4 out_Color;
uniform mat4 u_Transform;
uniform vec4 u_Color;
uniform mat4 u_ProjectionView;

void main(void) { 
    gl_Position = u_ProjectionView * u_Transform * vec4(a_Position, 1.0);
    out_Color = u_Color;
}
