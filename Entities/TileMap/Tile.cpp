#include "Tile.h"

Tile::Tile(Color col, bool is_empty) : color(col), isEmpty(is_empty)
{
    id = IDGenerator<Tile>::GetID();
}

Color Tile::GetColor()
{
    return color;
}

bool Tile::IsEmpty() const
{
    return isEmpty;
}
