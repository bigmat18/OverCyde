#include "AnimRendererComponent.h"
#include "../Entity.h"
#include "../Rendering/Shader.h"
#include "../Rendering/Texture.h"
#include "../Rendering/Shape.h"

AnimRendererComponent::AnimRendererComponent(Entity *entity,
                                             Shape *shape,
                                             Shader *shader,
                                             uint8_t updateOrder) : RendererComponent(entity, shape, shader, updateOrder),
                                                                    currentFrame(0.0f),
                                                                    animFps(20.0f) {}

AnimRendererComponent::~AnimRendererComponent() {}

void AnimRendererComponent::Update(int deltaTime) {
    if(this->textures.size() > 0) {
        this->currentFrame += animFps * deltaTime;
        while (this->currentFrame >= this->textures.size())
            this->currentFrame -= this->textures.size();
        this->SetTexture(this->textures[static_cast<int>(this->currentFrame)]);
    }
}

void AnimRendererComponent::SetTextures(const std::vector<Texture *> &textures) {
    this->textures = textures;
    if (this->textures.size() > 0) {
        this->currentFrame = 0.0f;
        this->SetTexture(this->textures[0]);
    }
}
