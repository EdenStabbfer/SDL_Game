#include "Tile.h"

Tile::Tile(Color col, int sz, bool is_empty, bool isSld) : color(col), size(sz), isEmpty(is_empty), isSolid(isSld)
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

bool Tile::IsSolid() const
{
    return isSolid;
}
