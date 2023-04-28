//
// Created by kufuk on 25.04.2023.
//

#ifndef TILE_H
#define TILE_H

#include "../../Graphics/Graphics.h"
#include "../../Utils/IDGenerator.h"
#include "../../Math/Math.h"

class Tile
{
public:
    explicit Tile(Color col, int size, bool is_empty = true, bool isSolid = false);

    Color GetColor();

    [[nodiscard]]
    bool IsEmpty() const;

    [[nodiscard]]
    bool IsSolid() const;

private:
    uint32_t id;
    int size;
    Color color;
    bool isEmpty;
    bool isSolid;
};

#endif //TILE_H
