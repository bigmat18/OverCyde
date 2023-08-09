#include "RendererComponent.h"
#include "../Rendering/Shader.h"
#include "../Rendering/Texture.h"
#include "../Rendering/Shape.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <glm/glm.hpp>

RendererComponent::RendererComponent(GameObj *gameObj,
                                     Shape *shape,
                                     Shader *shader,
                                     int updateOrder) : Component(gameObj, updateOrder),
                                                        shape(shape),
                                                        shader(shader),
                                                        model(glm::mat4(1)),
                                                        texture(nullptr) {}

RendererComponent::~RendererComponent() {}

void RendererComponent::Draw(GLFWwindow *window, glm::mat4 projection, glm::mat4 view) {
    // GameObjData *data = this->gameObj->GetGameObjData();

    // this->model = glm::translate(this->model, data->GetPosition());
    // this->model = glm::rotate(this->model, glm::radians(data->GetRotation()), data->GetRotationVec());
    // this->model = glm::scale(this->model, data->GetScale());

    // this->shader->setMatrix4("projection", projection);
    // this->shader->setMatrix4("model", model);
    // this->shader->setMatrix4("view", view);
    
    if(this->texture) {
        std::cout << this->texture << std::endl;
        this->texture->Bind();
        std::cout << "YEA2" << std::endl;
        this->shape->Draw();
        std::cout << "YEA3" << std::endl;
    }
}