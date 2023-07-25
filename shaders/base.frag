#version 330 core  

out vec4 outColor; 
in vec4 fragColor; 


void main(void) { 
    outColor = fragColor;
} 