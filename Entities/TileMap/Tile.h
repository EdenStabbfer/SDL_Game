//
// Created by kufuk on 25.04.2023.
//

#ifndef TILE_H
#define TILE_H

#include "../../Graphics/Graphics.h"
#include "../../Utils/IDGenerator.h"


class Tile
{
public:
    explicit Tile(Color col, bool is_empty = true);

    Color GetColor();

    [[nodiscard]]
    bool IsEmpty() const;

private:
    uint32_t id;
    Color color;
    bool isEmpty;
};

#endif //TILE_H
