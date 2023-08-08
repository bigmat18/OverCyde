#version 330 core  

out vec4 FragColor; 

in vec4 ourColor; 
in vec2 TexCoords;

uniform sampler2D ourTexture;


void main(void) { 
    FragColor = texture(ourTexture, TexCoord);
} 