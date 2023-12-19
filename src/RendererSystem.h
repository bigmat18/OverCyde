#include <vector>
#include <SDL.h>
#include <glm/mat4x4.hpp>

#ifndef RENDERER_HANDLER_H
#define RENDERER_HANDLER_H

class RendererSystem {
    public:
        RendererSystem(class ViewMatrix *view);
        ~RendererSystem();

        void AddElement(class RendererComponent *element);
        void RemoveElement(class RendererComponent *element);

        void Initialize();
        void Shutdown();
        void Update();

    private:
        glm::mat4 m_projection;
        class ViewMatrix *m_view;
        SDL_Window *m_window;
        SDL_GLContext *m_context;
        std::vector<class RendererComponent *> m_objs;
};

#endif
