#include "Component.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef RENDERER_OBJ_H
#define RENDERER_OBJ_H

class RendererComponent : public Component {
    public:
        RendererComponent(class GameObj *gameObj,
                          class Shape *shape,
                          class Shader *shader,
                          GLshort updateOrder = 0);

        ~RendererComponent();

        virtual void Draw(GLFWwindow *window, glm::mat4 projection, glm::mat4 view);
        void SetTexture(class Texture *texture) { this->texture = texture; };

    protected:
        class Texture *texture;
        class Shape *shape;
        class Shader *shader;
        glm::mat4 model;

};

#endif