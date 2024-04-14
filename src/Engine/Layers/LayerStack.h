#pragma once
#include "Layer.h"
#include "../Core/Pch.h"

namespace Engine {
    class LayerStack {
        public:
            LayerStack() = default;
            ~LayerStack();

            /**
             * Append element to the stack (begining of vector).
            */
            void PushLayer(Layer* layer);

            /**
             * Appends a new element to the end of the stack.
             */
            void PushOverlay(Layer* overlay);

            /**
             * Remove the last element.
            */
            void PopLayer(Layer* layer);

            /**
             * Remove the first element.
            */
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() { return this->m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return this->m_Layers.end(); }
            std::vector<Layer*>::reverse_iterator rbegin() { return this->m_Layers.rbegin(); }
            std::vector<Layer*>::reverse_iterator rend() { return this->m_Layers.rend(); }

        private:
            std::vector<Layer*> m_Layers;
            unsigned int m_LayerInsertIndex = 0;
    };
}