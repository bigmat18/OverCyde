#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#ifndef SHADER_H
#define SHADER_H

class Shader {
    public:
        GLuint ID;

        Shader(const char* vertexPath, const char* fragmentPath);
        void use() const;

        void setBool(const std::string &name, bool value) const {
            glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value);
        }

        void setInt(const std::string &name, int value) const {
            glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
        }

        void setFloat(const std::string &name, float value) const {
            glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
        }

        void setMatrix4(const std::string &name, glm::mat4 matrix) const {
            glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
        }

        void setVec3(const std::string &name, glm::vec3 vector) const {
            glUniform3f(glGetUniformLocation(this->ID, name.c_str()), vector.x, vector.y, vector.z);
        }

    private:
        GLuint vertexShader;
        GLuint fragmentShader;

        std::string readFile(const char *path);
        bool createShader(const char *shaderCode, const GLuint type);
        void createProgram();
};

#endif