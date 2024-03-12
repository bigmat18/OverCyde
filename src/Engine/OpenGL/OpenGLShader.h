#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Renderer/Shader.h"
#include "../Core/Pch.h"

namespace Engine {
    class OpenGLShader : public Shader {
        public:
            OpenGLShader(const std::string &vertexPath, const std::string &fragmentPath);
            virtual ~OpenGLShader();

            virtual void Bind() const override;
            virtual void Unbind() const override;

            void SetBool(const std::string &name, bool value) const;
            void SetInt(const std::string &name, int value) const;
            void SetFloat(const std::string &name, float value) const;
            
            void SetMatrix4(const std::string &name, glm::mat4 matrix) const;

            void SetVec2(const std::string &name, glm::vec2 vector) const;
            void SetVec3(const std::string &name, glm::vec3 vector) const;
            void SetVec4(const std::string &name, glm::vec4 vector) const;

        private:
            std::string ReadFile(const std::string &path);
            bool CreateShader(const char *shaderCode, const uint32_t type);
            void CreateProgram();

        private:
            uint32_t m_ID;
            uint32_t m_VertexID;
            uint32_t m_FragmentID;
    };
}