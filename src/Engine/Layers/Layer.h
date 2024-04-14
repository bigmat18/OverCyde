#pragma once
#include "../Events/Event.h"

namespace Engine {
    class Layer {
        public:
            /**
             * The Layer constructor
             * @param name the name of layer, it's used for debug porpouse
            */
            Layer(const std::string &name = "Layer") : m_DebugName(name) {};
            virtual ~Layer() = default;

            /**
             * This method is used when the layer is added 
            */
            virtual void OnAttach() {};

            /**
             * This method is used when the layer is removed
             */
            virtual void OnDetach() {};

            /**
             * This method is used in every iteration in Application loop.
             * In this method you should write the logic of layer.
             * @param deltaTime this value rappreset the time between the current iteration and last iteration
             */
            virtual void OnUpdate(float deltaTime) {};

            /**
             * This method is used when Application process event from layer.
             * In this method you should attack event to a method with EventDispatch
             * @param event is the event processed
             */
            virtual void OnEvent(Event& event) {};


            virtual void OnImGuiRender() {};

            /**
             * Get the name of layer
             * @return return a std::string referecne to name
            */
            inline const std::string& GetName() const { return m_DebugName; }

        private:
            std::string m_DebugName;
    };
}
