//
// Created by kufuk on 27.04.2023.
//

#ifndef IEVENTCALLABLE_H
#define IEVENTCALLABLE_H

#include <SDL.h>

class IEventCallable
{
    friend class Engine;

protected:
    virtual void Callback(SDL_Event& event, const Uint8* keyboard) = 0;
};

#endif //IEVENTCALLABLE_H
