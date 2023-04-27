//
// Created by kufuk on 27.04.2023.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <list>
#include <iostream>

#include "Graphics/Components/IDrawable.h"
#include "Graphics/Components/IUpdatable.h"
#include "Graphics/Components/IEventCallable.h"

class Engine
{
    using ObjectsToCallback = std::list<IEventCallable*>;
    using ObjectsToUpdate = std::list<IUpdatable*>;
    using ObjectsToRender = std::list<IDrawable*>;

public:
    Engine();
    ~Engine();

    static void Init(const char *title, Vector2i pos, Vector2u size);

    static void HandleEvents();
    static void Update();
    static void Render();
    static void Run();

    static void Clean();

    static SDL_Renderer*    GetRenderer();
    static SDL_Window*      GetWindow();
    static Camera*          GetCamera();

    static void AddDrawable(IDrawable& obj);
    static void AddUpdatable(IUpdatable& obj);
    static void AddCallable(IEventCallable& obj);

private:
    static SDL_Window*          window;
    static SDL_Renderer*        renderer;
    static Camera*              camera;

    static ObjectsToCallback*   toCallback;
    static ObjectsToRender*     toRender;
    static ObjectsToUpdate*     toUpdate;

    static bool                 isRunning;

    static float                deltaTime;

public:
    static enum WindowMode
    {
        WINDOWED,
        FULLSCREEN
    } WindowMode;
};


#endif //ENGINE_H
