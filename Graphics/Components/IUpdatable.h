//
// Created by kufuk on 27.04.2023.
//

#ifndef IUPDATABLE_H
#define IUPDATABLE_H


class IUpdatable
{
    friend class Engine;

protected:
    virtual void Update(const float& deltaTime) = 0;
};


#endif //IUPDATABLE_H
