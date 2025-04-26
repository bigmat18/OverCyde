#include <Input/GLFWInput.h>

#include <GLFW/glfw3.h> 
#include <Application.h>

namespace Engine {
    Input *Input::s_Instance = new GLFWInput();

    bool GLFWInput::IsKeyPressedImpl(const KeyCode key) {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS;
    }

    bool GLFWInput::IsMouseButtonPressedImpl(const MouseCode button) {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    glm::vec2 GLFWInput::GetMousePositionImpl() {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {(float)xpos, (float)ypos};
    }

    float GLFWInput::GetMouseXImpl() {
        return GetMousePosition().x;
    }

    float GLFWInput::GetMouseYImpl() {
        return GetMousePosition().y;
    }
}