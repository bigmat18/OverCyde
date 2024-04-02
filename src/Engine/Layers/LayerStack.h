#pragma once
#include "Layer.h"
#include "../Core/Pch.h"

namespace Engine {
    class LayerStack {
        public:
            LayerStack();
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

            std::vector<Layer*> GetLayers() const { return this->m_Layers; }

            std::vector<Layer*>::iterator begin() { return this->m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return this->m_Layers.end(); }

        private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerInsert;
    };
}