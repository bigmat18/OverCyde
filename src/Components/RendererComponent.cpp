#include "RendererComponent.h"
#include <iostream>

RendererComponent::RendererComponent(GameObj *gameObj,
                                     int updateOrder = 0,
                                     std::vector<Texture *> textures,
                                     Shape *shape,
                                     Shader *shader) : Component(gameObj, updateOrder),
                                                       textures(textures),
                                                       shape(shape),
                                                       shader(shader),
                                                       model(glm::mat4(1)),
                                                       currentFrame(0.0f),
                                                       animFps(20.0f)
{ this->texture = this->textures[0]; }

RendererComponent::~RendererComponent() {}

void RendererComponent::Update(int deltaTime) {
    if(this->textures.size() > 0) {
        this->currentFrame += animFps * deltaTime;

        while (this->currentFrame >= this->textures.size())
            this->currentFrame -= this->textures.size();

        this->texture = this->textures[static_cast<int>(this->currentFrame)];
    }
}

void RendererComponent::Draw(GLFWwindow *window, glm::mat4 projection, glm::mat4 view) {
    
}