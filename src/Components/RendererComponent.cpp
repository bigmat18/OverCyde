#include "RendererComponent.h"
#include "../Rendering/Shader.h"
#include "../Rendering/Texture.h"
#include "../Rendering/Texture2D.h"
#include "../Rendering/Shape.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/glm.hpp>

RendererComponent::RendererComponent(Entity *entity,
                                     Shape *shape,
                                     Shader *shader,
                                     short int updateOrder) : Component(entity, updateOrder),
                                                              texture(nullptr),
                                                              shape(shape),
                                                              shader(shader),
                                                              model(glm::mat4(1)) {}

RendererComponent::~RendererComponent() {
    delete this->shape;
    delete this->shader;
    delete this->texture;
}

void RendererComponent::Draw(glm::mat4 projection, glm::mat4 view) {
    this->model = glm::translate(glm::mat4(1), this->m_entity->GetPosition());
    this->model = glm::rotate(this->model, glm::radians(this->m_entity->GetRotation()), this->m_entity->GetRotationVec());
    this->model = glm::scale(this->model, this->m_entity->GetScale());

    this->shader->use();
    this->shader->setMatrix4("model", this->model);
    this->shader->setMatrix4("view", view);
    this->shader->setMatrix4("projection", projection);

    this->texture->Bind();
    this->shape->Draw();
}
