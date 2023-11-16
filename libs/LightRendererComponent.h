#include "RendererComponent.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef LIGHT_RENDERER_COMPONENT_H
#define LIGHT_RENDERER_COMPONENT_H

class LightRendererComponent : public RendererComponent {
    public:
        LightRendererComponent(class GameObj *gameObj,
                              class Shape *shape,
                              class Shader *shader,
                              GLshort updateOrder = 0);

        ~LightRendererComponent();

        void Draw(GLFWwindow *window, glm::mat4 projection, glm::mat4 view) override;
        class FrameBuffer* GetFBO() const { return this->m_FBO; }
        
    private:
        class FrameBuffer *m_FBO;
        class Shader *m_depthShader;
};

#endif