#pragma once
#include "../Pch.h"
#include "../Macro.h"

namespace Core {
    enum class ShaderDataType {
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type) {
        switch (type){
            case ShaderDataType::None:      LOG_CORE_ERROR("ShaderDataType::None not supported");
            case ShaderDataType::Float:     return 4;
            case ShaderDataType::Float2:    return 4 * 2;
            case ShaderDataType::Float3:    return 4 * 3;
            case ShaderDataType::Float4:    return 4 * 4;
            case ShaderDataType::Mat3:      return 4 * 3 * 3;
            case ShaderDataType::Mat4:      return 4 * 4 * 4;
            case ShaderDataType::Int:       return 4;
            case ShaderDataType::Int2:      return 4 * 2;
            case ShaderDataType::Int3:      return 4 * 3;
            case ShaderDataType::Int4:      return 4 * 4;
            case ShaderDataType::Bool:      return 1;
        }
        CORE_ASSERT(false, "Unknow shader data type");
        return 0;
    }

    struct VertexBufferElement {
        std::string Name;
        ShaderDataType Type;
        uint32_t Size;
        uint32_t Offset;
        bool Normalized;

        VertexBufferElement() {};

        VertexBufferElement(const std::string& name, ShaderDataType type, bool normalized = false) 
            : Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) {}

        uint32_t GetComponentCount() const {
            switch (Type) {
                case ShaderDataType::None:      LOG_CORE_ERROR("ShaderDataType::None not supported");
                case ShaderDataType::Float:     return 1;
                case ShaderDataType::Float2:    return 2;
                case ShaderDataType::Float3:    return 3;
                case ShaderDataType::Float4:    return 4;
                case ShaderDataType::Mat3:      return 3 * 3;
                case ShaderDataType::Mat4:      return 4 * 4;
                case ShaderDataType::Int:       return 1;
                case ShaderDataType::Int2:      return 2;
                case ShaderDataType::Int3:      return 3;
                case ShaderDataType::Int4:      return 4;
                case ShaderDataType::Bool:      return 1;
            }
            CORE_ASSERT(false, "Unknow shader data type");
            return 0;
        }
    };


    class VertexBufferLayout {
        public:
            VertexBufferLayout() {};
            VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements) 
                : m_Elements(elements) 
            { this->CalculateOffsetAndStride(); }

            ~VertexBufferLayout() {};

            inline const std::vector<VertexBufferElement>& GetElements() const { return this->m_Elements; }
            inline uint32_t GetStride() const { return this->m_Stride; }

            std::vector<VertexBufferElement>::iterator begin() { return this->m_Elements.begin(); }
            std::vector<VertexBufferElement>::iterator end() { return this->m_Elements.end(); }

            const std::vector<VertexBufferElement>::const_iterator begin() const { return this->m_Elements.begin(); }
            const std::vector<VertexBufferElement>::const_iterator end() const { return this->m_Elements.end(); }

        private:
            void CalculateOffsetAndStride() {
                uint32_t offset = 0;
                this->m_Stride = 0;
                for (auto &element : this->m_Elements) {
                    element.Offset = offset;
                    offset += element.Size;
                    this->m_Stride += element.Size;
                }
            }

        private:
            std::vector<VertexBufferElement> m_Elements;
            uint32_t m_Stride = 0;
    };

    class VertexBuffer {
        public: 
            virtual ~VertexBuffer() = default;

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            virtual const void SetLayout(const VertexBufferLayout& layout) = 0;
            virtual const VertexBufferLayout& GetLayout() const = 0; 

            static VertexBuffer *Create(float *vertices, uint32_t size);
    };

    class IndexBuffer {
        public:
            virtual ~IndexBuffer() = default;

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            static IndexBuffer *Create(uint32_t *indices, uint32_t size);
    };
}