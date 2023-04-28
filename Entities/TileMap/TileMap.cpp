//
// Created by kufuk on 25.04.2023.
//

#include "TileMap.h"

TileMap::TileMap() :
        mapSize(0, 0),
        tileSize(0)
{}

TileMap::TileMap(Vector2i map_size, int tile_size, const char* filename) :
        mapSize(map_size),
        tileSize(tile_size)
{
    if (strlen(filename) == 0)
        return;

    tileIds.resize(map_size.x);
    for (int i{0}; i < map_size.x; i++)
        tileIds[i].resize(map_size.y, 0);

    LoadMapFromFile(filename);
}


void TileMap::LoadMapFromFile(const char *filename)
{
    std::ifstream mapFile;
    mapFile.open(filename, std::ios::in);
    if (!mapFile.is_open())
        std::cerr << "Couldn't load map from file \"" << filename << "\"" << std::endl;
    std::string line;
    int j{0};
    while(std::getline(mapFile, line))
    {
        for (int i{0}; i < mapSize.x; i++)
        {
            char c = line[i];
            uint32_t id = atoi(&c);
            tileIds[i][j] = id;
        }
        j++;
    }
    mapFile.close();

}

void TileMap::Render(SDL_Renderer* renderer, Camera* camera)
{
    for (int i{0}; i < mapSize.x; i++)
    {
        for (int j{0}; j < mapSize.y; j++)
        {
            SDL_Rect rect;
            rect.x = i*tileSize + camera->GetOffset().x;
            rect.y = j*tileSize + camera->GetOffset().y;
            rect.w = tileSize;
            rect.h = tileSize;

            uint32_t  tileId = tileIds[i][j];
            if (tileId < tileSet.size())
            {
                Color c = tileSet[tileId].GetColor();
                SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
                SDL_RenderDrawRect(renderer, &rect);
                if (!tileSet[tileId].IsEmpty())
                    SDL_RenderFillRect(renderer, &rect);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255);
                SDL_RenderDrawRect(renderer, &rect);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    SDL_Rect highlightedRect = { cursorPosition.x * tileSize + camera->GetOffset().x,
                                 cursorPosition.y * tileSize + camera->GetOffset().y ,
                                 tileSize,
                                 tileSize
    };
    SDL_SetRenderDrawColor(renderer, 255, 195, 15, 255);
    SDL_RenderDrawRect(renderer, &highlightedRect);
}

void TileMap::MouseUpdate(const Camera *camera)
{
    Vector2i mousePos{0};
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    Vector2f dist = (Vector2f)mousePos/camera->GetScale() + camera->GetPosition() - camera->GetHalfSize();
    cursorPosition = dist / tileSize;
    if (dist.x < 0) cursorPosition.x -= 1;
    if (dist.y < 0) cursorPosition.y -= 1;
    SDL_SetWindowTitle(camera->GetWindow(), (std::to_string(cursorPosition.x) + " " + std::to_string(cursorPosition.y)).c_str());
}

const Tile& TileMap::GetTile(Vector2i pos) const
{
    if (pos < Vector2i(0) || pos > mapSize)
        return tileSet[0];
    return tileSet[tileIds[pos.x][pos.y]];
}

int TileMap::GetTileSize() const
{
    return tileSize;
}
