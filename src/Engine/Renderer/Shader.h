#pragma once
#include "../Core/Pch.h"

namespace Core {
    class Shader {
        public:
            virtual ~Shader() = default;

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            static Shader *Create(const std::string &vertexPath, const std::string &fragmentPath);
    };
}

