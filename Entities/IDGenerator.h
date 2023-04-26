//
// Created by kufuk on 25.04.2023.
//

#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <cstdint>

template<class T>
class IDGenerator
{
    static uint32_t id_counter;

public:
    static uint32_t GetID()
    {
        return id_counter++;
    }

    static uint32_t GetCount()
    {
        return id_counter;
    }
};


#endif //IDGENERATOR_H
