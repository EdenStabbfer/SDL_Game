//
// Created by kufuk on 28.04.2023.
//

#ifndef IMOUSECONTROLLABLE_H
#define IMOUSECONTROLLABLE_H

#include "../Camera.h"

class IMouseControllable
{
    friend class Engine;

protected:

    virtual void MouseUpdate(const Camera* camera) = 0;
};

#endif //IMOUSECONTROLLABLE_H
