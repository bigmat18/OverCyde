#version 330 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec2 a_TexCoord;

out vec4 out_Color;
out vec2 out_TexCoord;

uniform vec4 u_Color;
uniform mat4 u_Transform;
uniform mat4 u_ProjectionView;


void main(void) { 
    gl_Position = u_ProjectionView * u_Transform * vec4(a_Position, 1.0);

    out_Color = u_Color;
    out_TexCoord = a_TexCoord;
}
