#include "RendererComponent.h"
#include "../Rendering/Shader.h"
#include "../Rendering/Texture.h"
#include "../Rendering/Shape.h"
#include "../GameObj.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

RendererComponent::RendererComponent(GameObj *gameObj,
                                     std::vector<Texture *> textures,
                                     Shape *shape,
                                     Shader *shader,
                                     int updateOrder) : Component(gameObj, updateOrder),
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
    GameObjData *data = this->gameObj->GetGameObjData();

    this->model = glm::translate(this->model, data->GetPosition());
    this->model = glm::rotate(this->model, glm::radians(data->GetRotation()), data->GetRotationVec());
    this->model = glm::scale(this->model, data->GetScale());

    this->shader->setMatrix4("projection", projection);
    this->shader->setMatrix4("model", model);
    this->shader->setMatrix4("view", view);

    this->texture->Bind();
    this->shape->Draw();
}