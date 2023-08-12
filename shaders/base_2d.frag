#version 330 core  

out vec4 FragColor; 

in vec2 TexCoords;
uniform sampler2D texture1;

void main(void) { 
    FragColor = texture(texture1, TexCoords);
} 