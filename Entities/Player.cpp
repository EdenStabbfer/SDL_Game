//
// Created by kufuk on 26.04.2023.
//

#include "Player.h"
#include <iostream>

Player::Player(Camera& cam, const Vector2f& pos, const Vector2i& sz) :
        position(pos),
        camera(cam),
        size(sz)
{}

void Player::SetPosition(const Vector2f &pos)
{
    position = pos;
    camera.SetNextPosition(pos);
}

const Vector2f &Player::GetPosition() const
{
    return position;
}

void Player::Move(const Vector2f &direction, const float& dt)
{
    position += direction * speed * dt;
    camera.SetNextPosition(position);
}

void Player::SetSpeed(float val)
{
    speed = val;
}

float Player::GetSpeed() const
{
    return speed;
}

void Player::SetSize(const Vector2u &s)
{
        size = s;
}

const Vector2u &Player::GetSize() const
{
    return size;
}

SDL_Rect Player::GetCollider() const
{
    return { static_cast<int>(position.x - (float)size.x / 2),
             static_cast<int>(position.y - (float)size.y / 2),
             static_cast<int>(size.x),
             static_cast<int>(size.y)
    };
}

void Player::Callback(SDL_Event &event, const Uint8 *keyboard)
{
    moveDirection = {0, 0};
    if (keyboard[SDL_SCANCODE_W])
        moveDirection.y = -1;
    if (keyboard[SDL_SCANCODE_S])
        moveDirection.y = 1;
    if (keyboard[SDL_SCANCODE_D])
        moveDirection.x = 1;
    if (keyboard[SDL_SCANCODE_A])
        moveDirection.x = -1;
}

void Player::Update(const float &dt)
{
    Move(moveDirection, dt);
}

void Player::Render(SDL_Renderer *renderer, Camera *camera)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_Rect rect = GetCollider();
    rect.x += camera->GetOffset().x;
    rect.y += camera->GetOffset().y;
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
}

void Player::SetMap(TileMap &tileMap)
{
    map = tileMap;
}
