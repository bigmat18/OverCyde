#version 330 core  

out vec4 FragColor; 

in vec4 out_Color;
in vec2 out_TexCoord;

uniform bool u_ActiveTex;
uniform sampler2D u_Texture;

void main(void) { 
    if(u_ActiveTex) {
        FragColor = texture(u_Texture, out_TexCoord);
    } else {
        FragColor = out_Color;
    }
}
