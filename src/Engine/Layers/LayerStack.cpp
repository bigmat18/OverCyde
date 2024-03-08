#include "LayerStack.h"

namespace Engine {
    
    LayerStack::LayerStack() {
        m_LayerInsert = this->m_Layers.begin();
    }

    LayerStack::~LayerStack() {
        for (auto layer : m_Layers) {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer){ 
        this->m_LayerInsert = this->m_Layers.emplace(m_LayerInsert, layer); 
    }

    void LayerStack::PushOverlay(Layer* overlay) { 
        this->m_Layers.emplace_back(overlay); 
    }

    void LayerStack::PopLayer(Layer* layer) {
        auto it = std::find(this->m_Layers.begin(), this->m_Layers.end(), layer);
        if (it != this->m_Layers.end()) {
            this->m_Layers.erase(it);
            this->m_LayerInsert--;
        }   
    }

    void LayerStack::PopOverlay(Layer* overlay) {
        auto it = std::find(this->m_Layers.begin(), this->m_Layers.end(), overlay);
        if(it != this->m_Layers.end()){
            this->m_Layers.erase(it);
        }
    }

}