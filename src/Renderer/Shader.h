#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Pch.h"

namespace Core {
    class Shader {
        public:
            Shader(const std::string& vertexPath, const std::string& fragmentPath);
            ~Shader();

            void Bind() const;
            void Unbind() const;

            void setBool(const std::string &name, bool value) const {
                glUniform1i(glGetUniformLocation(this->m_ID, name.c_str()), (int)value);
            }

            void setInt(const std::string &name, int value) const {
                glUniform1i(glGetUniformLocation(this->m_ID, name.c_str()), value);
            }

            void setFloat(const std::string &name, float value) const {
                glUniform1f(glGetUniformLocation(this->m_ID, name.c_str()), value);
            }

            void setMatrix4(const std::string &name, glm::mat4 matrix) const {
                glUniformMatrix4fv(glGetUniformLocation(this->m_ID, name.c_str()), 1, false, glm::value_ptr(matrix));
            }

            void setVec3(const std::string &name, glm::vec3 vector) const {
                glUniform3f(glGetUniformLocation(this->m_ID, name.c_str()), vector.x, vector.y, vector.z);
            }

        private:
            std::string ReadFile(const std::string& path);
            bool CreateShader(const char* shaderCode, const uint32_t type);
            void CreateProgram();
            
            uint32_t m_ID;
            uint32_t m_VertexID;
            uint32_t m_FragmentID;

    };
}

