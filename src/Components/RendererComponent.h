#include "Component.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>

#ifndef RENDERER_OBJ_H
#define RENDERER_OBJ_H

class RendererComponent : private Component {
    public:
        RendererComponent(class GameObj *gameObj, 
                          int updateOrder = 0, 
                          std ::vector<class Texture *> textures, 
                          class Shape *shape, 
                          class Shader *shader);
                          
        ~RendererComponent();

        void Update(int deltaTime) override;
        void Draw(GLFWwindow *window, glm::mat4 projection, glm::mat4 view);

    private:
        std::vector<class Texture*> textures;
        class Shape *shape;
        class Shader *shader;
        glm::mat4 model;

        float currentFrame;
        float animFps;
        class Texture *texture;
};

#endif