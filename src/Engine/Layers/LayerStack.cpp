#include "LayerStack.h"

namespace Engine {

    LayerStack::~LayerStack() {
        for (auto layer : m_Layers) {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer){
        this->m_Layers.emplace(this->m_Layers.begin() + m_LayerInsertIndex, layer);
        this->m_LayerInsertIndex++;
        layer->OnAttach();
    }

    void LayerStack::PushOverlay(Layer* overlay) { 
        this->m_Layers.emplace_back(overlay);
        overlay->OnAttach();
    }

    void LayerStack::PopLayer(Layer* layer) {
        auto it = std::find(this->m_Layers.begin(), this->m_Layers.end(), layer);
        if (it != this->m_Layers.end()) {
            layer->OnDetach();
            this->m_Layers.erase(it);
            this->m_LayerInsertIndex--;
        }   
    }

    void LayerStack::PopOverlay(Layer* overlay) {
        auto it = std::find(this->m_Layers.begin(), this->m_Layers.end(), overlay);
        if(it != this->m_Layers.end()){
            overlay->OnDetach();
            this->m_Layers.erase(it);
        }
    }

}