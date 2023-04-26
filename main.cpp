#include "SDL.h"
#include "Math/Math.h"
#include "Entities/TileMap/TileMap.h"
#include "Entities/Camera.h"
#include "Entities/Player.h"

enum WindowMode
{
    WINDOWED,
    FULLSCREEN
};

void Init(const char*, Vector2i, Vector2i, WindowMode);
void HandleEvents();
void Update(const float &dt);
void Render();
void Clean();
void DrawCircle(Vector2f pos, int radius, SDL_Color col, int n);

bool isRunning {false};

SDL_Window* window {nullptr};
SDL_Renderer* renderer {nullptr};
const Uint8* keyboard {nullptr};


TileMap tileMap;
Camera camera({0, 0}, window);
Player player({0, 0}, camera, 2);

int main(int argc, char* args[])
{
    int width {1280}, height{720};
    camera.SetMoveSpeed(0.01);
    camera.SetScale(4);
    camera.SetSize({static_cast<double>(width), static_cast<double>(height)});

    tileMap = TileMap({100, 100}, 32*camera.GetScale(), "map1.txt");
    tileMap.AddTile(Color(0, 0, 0, 0));                 // 0 - воздух
    tileMap.AddTile(Color(70, 75, 70), false);          // 1 - пол
    tileMap.AddTile(Color(30, 35, 30, 255), false);     // 2 - стена
    tileMap.AddTile(Color(65, 175, 70), false);         // 3 - трава
    tileMap.AddTile(Color(227, 227, 45), false);        // 4 - объект

    Init("Test game", {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}, {width, height}, WINDOWED);

    while (isRunning)
    {
        HandleEvents();
        Update(1);
        Render();
    }
    Clean();
    return 0;
}


void Update(const float &dt)
{
    Vector2f moveDir{0};
    if (keyboard[SDL_SCANCODE_W])
        moveDir.y = -1;
    if (keyboard[SDL_SCANCODE_S])
        moveDir.y = 1;
    if (keyboard[SDL_SCANCODE_D])
        moveDir.x = 1;
    if (keyboard[SDL_SCANCODE_A])
        moveDir.x = -1;
    player.Move(moveDir.normalized(), dt);

    camera.Update(dt);
}

void Render()
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    //Render queue
    Vector2f offset = camera.GetOffset();
    tileMap.Draw(renderer, offset);
    DrawCircle(player.GetPosition() + offset + camera.GetSize() / 2, 16, {255, 0, 0,255}, 30);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

void Init(const char *title, Vector2i pos, Vector2i size, WindowMode wm)
{
    Uint8 flags = SDL_WINDOW_SHOWN;

    try
    {
        if (wm == FULLSCREEN)
            flags |= SDL_WINDOW_FULLSCREEN;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
            throw std::runtime_error("Init SDL subsystems error");

        window = SDL_CreateWindow(title, pos.x, pos.y, size.x, size.y, flags);

        if (!window)
            throw std::runtime_error("Create SDL Window error");

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (!renderer)
            throw std::runtime_error("Create SDL Window error");

        isRunning = true;
        std::cout << "App \"" << title << "\" initialised..." << std::endl;
    }
    catch (const std::exception &e)
    {
        isRunning = false;
        std::cout << "SDL init error: " << e.what() << std::endl;
    }
}

void HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }

    SDL_PumpEvents();
    keyboard = SDL_GetKeyboardState(nullptr);
}

void DrawCircle(Vector2f pos, int radius, SDL_Color col, int n)
{
    double ds = sin(2*std::numbers::pi / n);
    double dc = cos(2*std::numbers::pi / n);
    double s{0}, c{1}, temp;

    SDL_Vertex vertices[3];
    for (int i{0}; i < n; i++)
    {
        vertices[0] = {{static_cast<float>(pos.x + radius*c), static_cast<float>(pos.y + radius*s)},
                       col, {1, 1}};
        vertices[1] = {{static_cast<float>(pos.x), static_cast<float>(pos.y)},
                       col, {1, 1}};
        temp = s;
        s = s*dc + c*ds;
        c = c*dc - temp*ds;
        vertices[2] = {{static_cast<float>(pos.x + radius*c), static_cast<float>(pos.y + radius*s)},
                       col, {1, 1}};
        SDL_RenderGeometry(renderer, nullptr, vertices, 3, nullptr, 0);
    }
}

void Clean()
{
    std::cout << "App \"" << SDL_GetWindowTitle(window) << "\" destroyed..." << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}