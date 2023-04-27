//
// Created by kufuk on 25.04.2023.
//

#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <fstream>
#include <iostream>

#include "Tile.h"
#include "../../Math/Math.h"
#include "../../Graphics/Components/IDrawable.h"


class TileMap : public IDrawable
{
    using Map = std::vector<std::vector<uint32_t>>;
    using TileSet = std::vector<Tile>;

public:
    TileMap();
    TileMap(Vector2i map_size, uint32_t tile_size, const char* filename = "");

    template<class ...ARGs>
    void AddTile(ARGs... args);

    void LoadMapFromFile(const char* filename);

    void Render(SDL_Renderer* renderer, Camera* camera) override;
private:
    Vector2i mapSize;
    uint32_t tileSize;

    Map tileIds;
    TileSet tileSet;
};


template<class... ARGs>
void TileMap::AddTile(ARGs... args)
{
    tileSet.emplace_back(std::forward<ARGs>(args)...);
}

#endif //TILEMAP_H
