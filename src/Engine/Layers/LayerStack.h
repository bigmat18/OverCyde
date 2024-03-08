#pragma once
#include "Layer.h"
#include "../Core/Pch.h"

namespace Engine {
    class LayerStack {
        public:
            LayerStack();
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);
            void PopLayer(Layer* layer);
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() { return this->m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return this->m_Layers.end(); }

        private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerInsert;
    };
}