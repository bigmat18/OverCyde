#version 330 core  

out vec4 FragColor; 

in vec3 TexCoords;
uniform samplerCube texture1;


void main(void) { 
    FragColor = texture(texture1, TexCoords);
} 