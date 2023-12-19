#include "Entity.h"
#include "Rendering/FrameBuffer.h"

#ifndef LIGHT_OBJ_H
#define LIGHT_OBJ_H

const glm::vec3 AMBIENT(0.05f, 0.05f, 0.05f);
const glm::vec3 DIFFUSE(0.8f, 0.8f, 0.8f);
const glm::vec3 SPECULAR(1.0f, 1.0f, 1.0f);

const GLfloat CONSTANT = 1.0f;
const GLfloat LINEAR = 0.09f;
const GLfloat QUADRATIC = 0.032f;

class LightEntity : public Entity {
    public:
        LightEntity(glm::vec3 m_ambient = AMBIENT,
                 glm::vec3 m_diffuse = DIFFUSE,
                 glm::vec3 m_specular = SPECULAR,
                 GLfloat m_constant = CONSTANT,
                 GLfloat m_linear = LINEAR,
                 GLfloat m_quadratic = QUADRATIC) : m_ambient(m_ambient),
                                                    m_diffuse(m_diffuse),
                                                    m_specular(m_specular),
                                                    m_constant(m_constant),
                                                    m_linear(m_linear),
                                                    m_quadratic(m_quadratic) {};

        ~LightEntity() {};

        glm::vec3 GetAmbient() const { return this->m_ambient; }
        glm::vec3 GetDiffuse() const { return this->m_diffuse; }
        glm::vec3 GetSpecular() const { return this->m_specular; }

        GLfloat GetConstant() const { return this->m_constant; }
        GLfloat GetLinear() const { return this->m_linear; }
        GLfloat GetQuadratic() const { return this->m_quadratic; }

    private:
        glm::vec3 m_ambient, 
                  m_diffuse, 
                  m_specular;

        GLfloat m_constant, 
                m_linear, 
                m_quadratic;
};

#endif
