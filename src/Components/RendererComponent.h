#include "Component.h"
#include <glm/glm.hpp>

#ifndef RENDERER_OBJ_H
#define RENDERER_OBJ_H

class RendererComponent : public Component {
    public:
        RendererComponent(class Entity *entity,
                          class Shape *shape,
                          class Shader *shader,
                          short int updateOrder = 0);

        ~RendererComponent();

        virtual void Draw(glm::mat4 projection, glm::mat4 view);
        void SetTexture(class Texture *texture) { this->texture = texture; };

    protected:
        class Texture *texture;
        class Shape *shape;
        class Shader *shader;
        glm::mat4 model;

};

#endif
