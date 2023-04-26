#include "App.h"
#include "Utils/TileMap/TileMap.h"

App *game{nullptr};

int main(int argc, char* args[])
{
    game = new App();
    game->Init("Test game", {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}, {1280, 720}, WINDOWED);

    TileMap<10, 10, 32> map("map1.txt");
    map.AddTile(Color(0, 0, 0, 0));       // 0 - воздух
    map.AddTile(Color(0, 0, 0, 127), false);    // 1 - стена
    map.AddTile(Color(128, 0, 0, 200), false);        // 2 - объект 1
    map.AddTile(Color(0, 128, 0));        // 3 - объект 2

    while (game->IsRunning())
    {
        game->HandleEvents();
        game->Update();
        map.Draw(game->GetRenderer());
        game->Render();

    }
    game->Clean();
    return 0;
}
