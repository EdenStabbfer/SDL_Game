//
// Created by kufuk on 26.04.2023.
//

#include "Player.h"

Player::Player(const Vector2f &pos, Camera &cam, float speed) :
        position(pos), camera(cam), speed(speed)
{}

void Player::Update(const float &dt)
{

}

void Player::SetPosition(const Vector2f &pos)
{
    position = pos;
    camera.SetNewPosition(pos);
}

const Vector2f &Player::GetPosition() const
{
    return position;
}

void Player::Move(const Vector2f &direction, const float& dt)
{
    position += direction * speed * dt;
    camera.SetNewPosition(position);
}

void Player::SetSpeed(float val)
{
    speed = val;
}

float Player::GetSpeed() const
{
    return speed;
}
