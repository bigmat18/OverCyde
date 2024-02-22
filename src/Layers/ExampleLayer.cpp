#include "ExampleLayer.h"
#include "../Log.h"

namespace Core {
    ExampleLayer::ExampleLayer() : Layer("Example") {}

    void ExampleLayer::OnAttach() {
        LOG_CORE_INFO("ExampleLayer::OnAttach");
    }

    void ExampleLayer::OnDetach() {
        LOG_CORE_INFO("ExampleLayer::OnDetach");
    }

    void ExampleLayer::OnUpdate() {
        LOG_CORE_INFO("ExampleLayer::OnUpdate");
    }

    void ExampleLayer::OnEvent(Event& event) {
        LOG_CORE_INFO("ExampleLayer::OnEvent");
    }
}