#version 330 core  

out vec4 FragColor; 

in vec4 out_Color;

void main(void) { 
    FragColor = out_Color;
}
