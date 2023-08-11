#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifndef VIEW_MATRIX_H
#define VIEW_MATRIX_H

class ViewMatrix {
    public:
        ViewMatrix() {
            this->SetView(glm::vec3(0.0f, 0.0f, 3.0f), 
                          glm::vec3(0.0f, 0.0f, -1.0f), 
                          glm::vec3(0.0f, 1.0f, 0.0f));
        }
        ~ViewMatrix() {}

        glm::mat4 GetView() const { return this->view; }

        void SetView(glm::vec3 position, glm::vec3 front, glm::vec3 up) {
            this->view = glm::rotate(glm::lookAt(position, position + front, up), glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        }

    private:
        glm::mat4 view;
};

#endif