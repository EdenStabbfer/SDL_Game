//
// Created by kufuk on 25.04.2023.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <cstdint>
#include <SDL.h>

struct Color
{
    uint8_t r, g, b, a;

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a){}
    Color(uint8_t r, uint8_t g, uint8_t b) : Color(r, g, b, 255){}
};

#endif //GRAPHICS_H
