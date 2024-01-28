#include "RendererComponent.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef ANIM_RENDERER_COMPONENT_H
#define ANIM_RENDERER_COMPONENT_H

class AnimRendererComponent : public RendererComponent {
    public:
        AnimRendererComponent(class Entity *entity,
                              class Shape *shape,
                              class Shader *shader,
                              uint8_t updateOrder = 0);

        ~AnimRendererComponent();

        void Update(int deltaTime) override;
        void SetTextures(const std::vector<Texture *> &textures);

    private:
        std::vector<class Texture*> textures;
        float currentFrame;
        float animFps;
};

#endif
