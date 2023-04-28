#include "SDL.h"
#include "Math/Math.h"
#include "Entities/TileMap/TileMap.h"
#include "Graphics/Camera.h"
#include "Entities/Player.h"

#include "Engine.h"



int main(int argc, char* args[])
{
    Vector2u windowSize = {1280, 720};

    Engine::Init("Test t", {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}, windowSize);

    Camera* camera = Engine::GetCamera();
    Engine::AddUpdatable(*camera);
    Engine::AddCallable(*camera);
    camera->SetMoveSpeed(0.03f);
    camera->SetScale(1);

    TileMap tileMap = TileMap({100, 100}, 32, "map1.txt");
    Engine::AddDrawable(tileMap);
    Engine::AddMouseUpdatable(tileMap);

    tileMap.AddTile(Color(0, 0, 0, 0), 32);                 // 0 - воздух
    tileMap.AddTile(Color(70, 75, 70), 32, false);          // 1 - пол
    tileMap.AddTile(Color(30, 35, 30, 255), 32, false, true);     // 2 - стена
    tileMap.AddTile(Color(65, 175, 70), 32, false);         // 3 - трава
    tileMap.AddTile(Color(227, 227, 45), 32, false);        // 4 - объект

    Player player(*camera, {200, 200}, {20, 20});
    Engine::AddCallable(player);
    Engine::AddUpdatable(player);
    Engine::AddDrawable(player);
    player.SetSpeed(2);

    Engine::Run();

    Engine::Clean();

    return 0;
}

//void DrawCircle(Vector2f pos, int radius, SDL_Color col, int n)
//{
//    double ds = sin(2*std::numbers::pi / n);
//    double dc = cos(2*std::numbers::pi / n);
//    double s{0}, c{1}, temp;
//
//    SDL_Vertex vertices[3];
//    for (int i{0}; i < n; i++)
//    {
//        vertices[0] = {{static_cast<float>(pos.x + radius*c), static_cast<float>(pos.y + radius*s)},
//                       col, {1, 1}};
//        vertices[1] = {{static_cast<float>(pos.x), static_cast<float>(pos.y)},
//                       col, {1, 1}};
//        temp = s;
//        s = s*dc + c*ds;
//        c = c*dc - temp*ds;
//        vertices[2] = {{static_cast<float>(pos.x + radius*c), static_cast<float>(pos.y + radius*s)},
//                       col, {1, 1}};
//        SDL_RenderGeometry(renderer, nullptr, vertices, 3, nullptr, 0);
//    }
//}