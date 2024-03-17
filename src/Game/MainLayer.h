#include <Engine.h>

using namespace Engine;

class MainLayer : public Layer {
    public:
        int counter = 0;

        void OnAttach() override {};

        void OnDetach() override {};

        void OnUpdate(float deltaTime) override;

        void OnEvent(Event& event) override;

        bool OnKeyPressed(KeyPressedEvent& kpe);
};