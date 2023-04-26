//
// Created by kufuk on 26.04.2023.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "../Math/Math.h"
#include "Camera.h"

class Player
{
public:
    Player(const Vector2f& pos, Camera& cam, float speed);

    void Update(const float& dt);

    void SetPosition(const Vector2f& pos);
    [[nodiscard]]
    const Vector2f& GetPosition() const;

    void SetSpeed(float val);
    [[nodiscard]]
    float GetSpeed() const;

    void Move(const Vector2f& , const float& dt);

private:
    Vector2f position;
    float speed;

    Camera& camera;
};


#endif //PLAYER_H
