//
// Created by kufuk on 25.04.2023.
//

#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <fstream>
#include <iostream>

#include "Tile.h"
#include "../../Graphics/Components/IDrawable.h"
#include "../../Graphics/Components/IMouseControllable.h"


class TileMap : public IDrawable, public IMouseControllable
{
    using Map = std::vector<std::vector<uint32_t>>;
    using TileSet = std::vector<Tile>;

public:
    TileMap();
    TileMap(Vector2i map_size, int tile_size, const char* filename = "");

    template<class ...ARGs>
    void AddTile(ARGs... args);

    void LoadMapFromFile(const char* filename);

    void Render(SDL_Renderer* renderer, Camera* camera) override;

    void MouseUpdate(const Camera* camera) override;

    [[nodiscard]]
    const Tile& GetTile(Vector2i pos) const;

    [[nodiscard]]
    int GetTileSize() const;

private:
    Vector2i mapSize;
    Vector2i cursorPosition{0};
    int tileSize;

    Map tileIds;
    TileSet tileSet;
};


template<class... ARGs>
void TileMap::AddTile(ARGs... args)
{
    tileSet.emplace_back(std::forward<ARGs>(args)...);
}

#endif //TILEMAP_H
