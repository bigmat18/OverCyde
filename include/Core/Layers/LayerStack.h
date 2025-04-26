#pragma once
#include <vector>
#include "Layer.h"

namespace Engine {
    class LayerStack {
        public:
            LayerStack() = default;
            ~LayerStack();

            /**
             * Append element to last position (without overlay)
            */
            void PushLayer(Layer* layer);

            /**
             * Appends a new element to the top to the stack (position size).
             */
            void PushOverlay(Layer* overlay);

            /**
             * Remove the first element.
            */
            void PopLayer(Layer* layer);

            /**
             * Remove the last element.
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