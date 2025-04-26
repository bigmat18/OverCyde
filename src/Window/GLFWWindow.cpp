#include <Window/GLFWWindow.h>

#include <GLFW/glfw3.h>

#include <Core/Utils.h>
#include <Core/Events/ApplicationEvent.h>
#include <Core/Events/KeyEvent.h>
#include <Core/Events/MouseEvent.h>

#include <Renderer/GraphicsContext.h>

namespace Engine {

    Window *Window::Create(const WindowProps &props) {
        return new GLFWWindow(props);
    }

    GLFWWindow::GLFWWindow(const WindowProps& props) { this->Initialize(props); }

    GLFWWindow::~GLFWWindow() { this->Shutdown(); }

    void GLFWWindow::Initialize(const WindowProps &props) {
        this->m_Data.Title = props.Title;
        this->m_Data.Width = props.Width;
        this->m_Data.Height = props.Height;


        ENGINE_ASSERT(glfwInit(), "Could not initialize GLFW!");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        this->m_Window = glfwCreateWindow(static_cast<int>(props.Width),
                                          static_cast<int>(props.Height),
                                          props.Title.c_str(), 
                                          nullptr, 
                                          nullptr);

        this->m_Context = GraphicsContext::Create(this->m_Window);
        this->m_Context->Initialize();

        glfwSetWindowUserPointer(this->m_Window, &this->m_Data);
        glfwSetWindowCloseCallback(this->m_Window, [](GLFWwindow *window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event); 
        });

        glfwSetWindowSizeCallback(this->m_Window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Height = height;
            data.Width = width;
            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetKeyCallback(this->m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
	            case GLFW_PRESS: {
	        	    KeyPressedEvent event(key, 0);
	        	    data.EventCallback(event);
	        	    break;
	            }
	            
	            case GLFW_RELEASE: {
	        	    KeyReleasedEvent event(key);
	        	    data.EventCallback(event);
	        	    break;
	            }
	        
	        	case GLFW_REPEAT: {
	        	    KeyPressedEvent event(key, true);
	        	    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keycode) {
	    	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

	    	KeyTypedEvent event(keycode);
	    	data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
	    	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

	    	switch (action) {
	    		case GLFW_PRESS: {
	    		    MouseButtonPressedEvent event(button);
	    		    data.EventCallback(event);
	    		    break;
	    		}
	    		case GLFW_RELEASE: {
	    		    MouseButtonReleasedEvent event(button);
	    		    data.EventCallback(event);
	    		    break;
	    		}
	    	} 
	    });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
	    	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	    	
	    	MouseScrolledEvent event((float)xOffset, (float)yOffset);
	    	data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
	    	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	    	
	    	MouseMovedEvent event((float)xPos, (float)yPos);
	    	data.EventCallback(event);
        });

    	const GLubyte* renderer	= glGetString(GL_RENDERER);
    	const GLubyte* vendor = glGetString(GL_VENDOR);
    	const GLubyte* version = glGetString(GL_VERSION);

    	LOG_ENGINE_INFO("GL Vendor          : {0}", reinterpret_cast<const char*>(vendor));
    	LOG_ENGINE_INFO("GL Renderer        : {0}", reinterpret_cast<const char*>(renderer));
    	LOG_ENGINE_INFO("GL Version (string): {0}", reinterpret_cast<const char*>(version));
    
    	#ifdef __APPLE__
                const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
                LOG_ENGINE_INFO("GLSL Version       : {0}", reinterpret_cast<const char *>(glslVersion));
    	#endif
    }

    void GLFWWindow::Shutdown() {
        glfwDestroyWindow(this->m_Window);
    }

    void GLFWWindow::OnUpdate() {
        glfwPollEvents();
        this->m_Context->SwapBuffers();
    }
}
