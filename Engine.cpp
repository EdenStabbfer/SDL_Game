//
// Created by kufuk on 27.04.2023.
//

#include "Engine.h"

void Engine::Init(const char *title, Vector2i pos, Vector2u size)
{
    Uint8 flags = SDL_WINDOW_SHOWN;

    try
    {
        if (WindowMode == FULLSCREEN)
            flags |= SDL_WINDOW_FULLSCREEN;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            throw std::runtime_error("Init SDL subsystems error");

        window = SDL_CreateWindow(title, pos.x, pos.y, (int)size.x, (int)size.y, flags);

        if (!window)
            throw std::runtime_error("Create SDL Window error");

        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        if (!renderer)
            throw std::runtime_error("Create SDL Window error");

        camera = new Camera({0, 0}, size);

        isRunning = true;
        std::cout << "App \"" << title << "\" initialised..." << std::endl;
    }
    catch (const std::exception &e)
    {
        isRunning = false;
        std::cout << "SDL init error: " << e.what() << std::endl;
    }
}

void Engine::Update()
{
    for (auto& obj : *toUpdate)
    {
        obj->Update(deltaTime);
    }
}

void Engine::Render()
{
//    DrawCircle(player.GetPosition() + offset + camera.GetSize() / 2, player.GetSize().x / 2, {255, 0, 0,255}, 30);
    SDL_RenderSetScale(renderer, camera->GetScale(), camera->GetScale());

    for (auto& obj : *toRender)
    {
        obj->Render(renderer, camera);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

void Engine::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    SDL_PumpEvents();
    const Uint8* keyboard = SDL_GetKeyboardState(nullptr);
    if (event.type == SDL_QUIT)
        isRunning = false;
    for (auto& obj : *toCallback)
    {
        obj->Callback(event, keyboard);
    }
}

void Engine::Clean()
{
    std::cout << "App \"" << SDL_GetWindowTitle(window) << "\" destroyed..." << std::endl;
    delete camera;
    delete toCallback;
    delete toRender;
    delete toUpdate;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Engine::Run()
{
    while(isRunning)
    {
        HandleEvents();
        Update();
        Render();
    }
}

SDL_Renderer* Engine::GetRenderer()
{
    return renderer;
}

SDL_Window* Engine::GetWindow()
{
    return window;
}

Camera* Engine::GetCamera()
{
    return camera;
}

void Engine::AddDrawable(IDrawable &obj)
{
    toRender->push_back(&obj);
}

void Engine::AddUpdatable(IUpdatable &obj)
{
    toUpdate->push_back(&obj);
}

void Engine::AddCallable(IEventCallable &obj)
{
    toCallback->push_back(&obj);
}

Engine::Engine() = default;
Engine::~Engine() = default;


SDL_Window* Engine::window = nullptr;
SDL_Renderer* Engine::renderer = nullptr;
Camera* Engine::camera = nullptr;

std::list<IDrawable*>* Engine::toRender = new std::list<IDrawable*>;
std::list<IUpdatable*>* Engine::toUpdate = new std::list<IUpdatable*>;
std::list<IEventCallable*>* Engine::toCallback = new std::list<IEventCallable*>;

bool Engine::isRunning = false;

float Engine::deltaTime = 1;

enum Engine::WindowMode Engine::WindowMode = WINDOWED;
