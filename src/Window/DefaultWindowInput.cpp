#include <Window/DefaultWindowInput.h>
#include <Core/Application.h>
#include <GLFW/glfw3.h> 

namespace Engine {
    Input *Input::s_Instance = new DefaultWindowInput();

    bool DefaultWindowInput::IsKeyPressedImpl(const KeyCode key) {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS;
    }

    bool DefaultWindowInput::IsMouseButtonPressedImpl(const MouseCode button) {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    glm::vec2 DefaultWindowInput::GetMousePositionImpl() {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {(float)xpos, (float)ypos};
    }

    float DefaultWindowInput::GetMouseXImpl() {
        return GetMousePosition().x;
    }

    float DefaultWindowInput::GetMouseYImpl() {
        return GetMousePosition().y;
    }
}