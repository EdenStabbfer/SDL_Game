//
// Created by kufuk on 27.04.2023.
//

#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <SDL.h>

#include "../Camera.h"

class IDrawable
{
    friend class Engine;

protected:
    virtual void Render(SDL_Renderer* renderer, Camera* camera) = 0;
};


#endif //IDRAWABLE_H
