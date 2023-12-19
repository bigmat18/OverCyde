#include "Shader.h"
#include "../Utils/DebuggingGL.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

Shader::Shader(const char *vertexPath, const char *fragmentPath){
    createShader(this->readFile(vertexPath).c_str(), GL_VERTEX_SHADER);
    createShader(this->readFile(fragmentPath).c_str(), GL_FRAGMENT_SHADER);
    this->createProgram();
    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragmentShader);
}

void Shader::use() const { glUseProgram(this->ID); }

bool Shader::createShader(const char *shaderCode, const GLuint type){
    GLuint shader;

    switch (type) {
        case GL_VERTEX_SHADER:
            shader = this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
            break;
        case GL_FRAGMENT_SHADER:
            shader = this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
    }

    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);

    int status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        check_shader(shader);
        return false;
    }
    return true;
}

void Shader::createProgram(){
    this->ID = glCreateProgram();
    glAttachShader(this->ID, this->vertexShader);
    glAttachShader(this->ID, this->fragmentShader);
    glLinkProgram(this->ID);
    validate_shader_program(this->ID);
}

std::string Shader::readFile(const char *path){
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        file.open(path);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        return stream.str();
    }catch(std::ifstream::failure e){
        std::cout << strerror(errno) << std::endl;
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    return nullptr;
}
