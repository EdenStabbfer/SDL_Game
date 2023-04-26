//
// Created by kufuk on 25.04.2023.
//

#include "IDGenerator.h"

class Tile;

template<> uint32_t IDGenerator<Tile>::id_counter = 0u;