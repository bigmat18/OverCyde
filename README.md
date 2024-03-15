# OverCyde Engine (not official name)
OverCyde game engine made from scratch in c++ with OpenGL to support the deploy of OverCyde's game. 
<div><img src="doc/logo.jpg" alt="drawing" width="300"/></div>

## Installation

For first you must clone the reposiory with submodule with (I suggest to forking the repo to work in easly wey):
```
git clone --recurse-submodules https://github.com/bigmat18/OverCyde.git
```
In the repository there are the followind dependecy:
- [GLFW](https://github.com/glfw/glfw): there are the .dll .dylib and .h files
- [glew](https://github.com/nigels-com/glew): there are the .dll .dylib and .h files
- [glm](https://github.com/g-truc/glm): there are the .hpp files (sub-repo)
- [spdlog](https://github.com/gabime/spdlog): there are the .cpp and .hpp files (sub.repo)
- [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h): there are only the stb_image.h file

## Building

### Makefile
To build **All project** (engine and game).
```
make buid_all
```
> **_NOTE:_**  Use this when you work with the engine and game at the same time.

Build only **engine** (this ceate .dylib or .dll):
```
make buid_engine
```
> **_NOTE:_**  Use this when you work with the only engine.

Build only **game**:
```
make buid_game
```
> **_NOTE:_**  Use this when you work with the only the game.


### Python script
To build all project (engine and game)
```
python ./build.py engine && python ./build.py game 
```
> **_NOTE:_**  Use this when you work with the engine and game at the same time.

Build only engine (this create .dylib or .dll):
```
python ./build.py engine
```
> **_NOTE:_**  Use this when you work with the only engine.

Build only game:
```
python ./build.py game
```
> **_NOTE:_**  Use this when you work with the only the game.

## Quick start
In Game/Game.cpp there is the base of game. For first things import the library:
```c++
#define ENGINE_PLATFORM
#include <Engine.h>
#include <EntryPoint.h>
```
- ```#include <Engine.h>``` import all the modules in engine.
- ```#include <EntryPoint.h>``` in this file there is the procedure to start application.

> **_WARN:_** ```#define ENGINE_PLATFORM``` is necessary to start engine without issues.

After that you should be create your Application class in the following wey:
```c++
class Game : public Engine::Application {  
    friend class Engine::Application;
};
```
In the class you must declare Engine::Application like [friend class](https://cplusplus.com/doc/tutorial/inheritance/#google_vignette) to access protected methods.<br/>
Now you must create the [constructor](https://learn.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170) to execute operation (like adding layer) when Game instance was created.
```c++
private:
    Game() : Engine::Application() {}
```
> **_NOTE:_** You must set the constructor private because the Application class (and sub-classes) are [Singleton Class](https://it.wikipedia.org/wiki/Singleton_(informatica)).

Now the most importat part to start application, you must define Application::Create() function in the following wey:
```c++
Engine::Application* Engine::Application::Create() {
    /* Execute code...*/
    return Engine::Application::SetInstance(new Game());
}
```
In this function you should execute the pre-creation instance scripts and than you must call the ```Engine::Application::SetInstance()``` to setup the Application, and pass your Application class' instance.

Now you can [build](##Building) the code and execute it with
```
make run
```
or
```
./bin/main.exe
```
and you can see this blanck window:
<div><img src="doc/default-window.png" alt="drawing" width="500"/></div>

The Background color, the title, height and the width can be changed using the ApplicationProps struct in the following wey:

```c++
class Game : public Engine::Application {  
    friend class Engine::Application;

    private:
        Game(const Engine::ApplicationProps& props) : Engine::Application(props) {
            this->PushLayer(new GameLayer());
        }
};

Engine::Application* Engine::Application::Create() {
    Engine::ApplicationProps props = Engine::ApplicationProps();
    props.WProps.Title = "Game";
    props.WProps.Width = 720;
    props.WProps.Height = 720;
    props.BGColor = Vec4f(HEX_COLOR(0xBF00FFFF));

    return Engine::Application::SetInstance(new Game(props));
}
```
> **_NOTE:_** the ```props.BGColor``` is a Vec4f(r, g, b, a), ```HEX_COLOR``` convert integer in 32 bit to r, g, b, a sequenze.

## Layer
Layers in a game engine is similar to layers in Photoshop, for example. This layer stack will determine the order in which things are drawn on the screen. Layers in a game engine are also applicable to events and update logic. For example:
- Game layer (Root)
- Debug layer
- UI layer
- Menu layer 
- ecc.

### Create your own layer
To create your own layer you should create a differte file, for example MyLayer.h, in his file include the base Engine dependency and declare your layer that inheritance base Layer class
```c++
class GameLayer : public Engine::Layer {}
```
From ```Engine::Layer``` you can override four method:

#### OnAttach
```c++
void OnAttach() override;
```
This method is call when Layer is added to LayerStack. <br/>
For example create base instace of other classes.

#### OnDetach
```c++
void OnDetach() override;
```
This method is call when Layer is removed from LayerStack. <br/>
For example dealloc all the memory allocate.

#### OnUpdate
```c++
void OnUpdate(float deltaTime) override;
```
This method is call every iteration of engine loop, in this method you should write the logic of layer. <br/><br/>
For example, in a game where a PG run continuely, in this method you can calculte the coordinate every frame.

#### OnEvent
```c++
void OnEvent(Event& event) override;
```
This method was call when the events stack is proceded, every layer is called in order and Application send event to OnEvent method. In this method you can be write the event callback using the event dispatcer (see [Event](##Events) section).

For example in a game where the PG can jump with space key, in OnEvent you can check if key is pressed and execute a callable function.

### Adding layer to Application
To add yout own layer to Application you can call one of this two method in the constructor of yout custom application class:

#### PushLayer
```c++
PushLayer(new YourLayer());
```
Adding layer at the end of layer stack.

#### PushOverlay
```c++
PushOverlay(new YourLayer());
```
Adding layer at the top of layer stack

## Events
Application needs to receive events to dispatch them to layers. The Window class will receive these events and communicate with Application class. Set up a call back function to pass event data to the Application.

The event system was implemented for application, mouse, key, and window events

To preocess events you must use the EventDispatech class, to use it create an instace (for example in OnEvent method in a [layer](####OnEvent))
```c++
EventDispatcher dispatcher = EventDispatcher(e);
```
Where e is the event to dispatch. To choose which function proccess each event call ```Dispatch``` method and use ```BIND_FUN``` to execute the bindding. 
```c++
dispatcher.Dispatch<WindowCloseEvent>(BIND_FUN(OnWindowClose));
```
In this example if event is of type WindowCloseEvent the dispatch send it to OnWindowClose, this function has this signature:
```c++
OnWindowClose(WindowCloseEvent& e)
```
> **_NOTE:_** When dispatech dispatch event to function it set it Handled, no other dispatech can handled it.

## Renderer2D
Renders the 2D graphics on the screen.
- **Maths**: this is the first step in building the rendering system. Aiming to have an optmized library quickly, [glm](https://github.com/g-truc/glm) will be used instead of creating a math library from scratch.

To init Renderer2D you must adding this line when init props in Create function:
```c++
props.RType = Renderer::RendererType::Renderer2D;
```

### Draw2DTriangle
Draw a triangle in a 2D space. You can change the position, size, color and rotate the shape.
```c++
Engine::Renderer::Draw2DTriangle(position, size, color, rotate);
```
<div><img src="doc/triangle.png" alt="drawing" width="150"/></div>

> **_NOTE:_** Every system of coordinate is manage with Engine type: Vec2f, Vec3f, Vec4f and they was in normalized space. For example:
```c++
Engine::Renderer::Draw2DTriangle(Engine::Vec2f(0.25f, 0.0f),
                                 Engine::Vec2f(0.125f, 0.125f),
                                 Engine::Vec4f(0.0f, 0.0f, 1.0f, 1.0f),
                                 45.0f);
```
This for example create a triangle in (x,y) = (0.25f, 0.0f), scale it for (x,y) = (0.125f, 0.125f) the color is (r, g, b, a) = (0.0f, 0.0f, 1.0f, 1.0f) and rotate of 45.0f.

> **_WARN:_** rotate is in degree.

### Draw2DSquare
Draw a square in a 2D space. You can change the position, size, color and rotate the shape.
```c++
Engine::Renderer::Draw2DSquare(position, size, color, rotate);
```
<div><img src="doc/square.png" alt="drawing" width="150"/></div>

> **_WARN:_** rotate is in degree.

### Draw2DCircle
Draw a circle in a 2D space. You can change the position, radius, color and rotate the shape.
```c++
Engine::Renderer::Draw2DCircle(position, radius, color, rotate);
```
<div><img src="doc/circle.png" alt="drawing" width="150"/></div>

> **_WARN:_** the radius must be positive.
> **_WARN:_** rotate is in degree.

### Draw2DPolyhedron
Draw a polyhedron in a 2D space.
```c++
Engine::Renderer::Draw2DPolyhedron(sides, position, size, color, rotate);
```
<div><img src="doc/polyhedron.png" alt="drawing" width="150"/></div>

> **_WARN:_** the sides param must be greater than or equal to 5.
> **_WARN:_** rotate is in degree.

## Logging
This will be a way to log events so the engine can communicate with the user. The goal is for the application to be the most client-facing possible. Because of that, it is nice to use a color code to differenciate the severity of the messages. It is also good to know where the log is coming from. Because of the extension of this work, an external library is used for printing messages.
```c++
LOG_CLIENT_TRACE("{0} {1}", var0, var1);

LOG_CLIENT_INFO("{0} {1}", var0, var1);

LOG_CLIENT_WARN("{0} {1}", var0, var1);

LOG_CLIENT_ERROR("{0} {1}", var0, var1);

LOG_CLIENT_CRITICAL("{0} {1}", var0, var1);
```