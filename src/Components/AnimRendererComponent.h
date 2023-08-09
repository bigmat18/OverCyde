#include "RendererComponent.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef ANIM_RENDERER_COMPO_H
#define ANIM_RENDERER_COMPO_H

class AnimRendererComponent : public RendererComponent {
    public:
        AnimRendererComponent(class GameObj *gameObj,
                              class Shape *shape,
                              class Shader *shader,
                              int updateOrder = 0);

        ~AnimRendererComponent();

        void Update(int deltaTime) override;
        void SetTextures(const std::vector<Texture *> &textures);

    private:
        std::vector<class Texture*> textures;
        float currentFrame;
        float animFps;
};

#endif