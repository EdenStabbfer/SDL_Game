//
// Created by kufuk on 26.04.2023.
//

#include "Camera.h"

Camera::Camera(const Vector2f &pos, const Vector2f &size) :
        currentPosition(pos),
        nextPosition(pos),
        size(size),
        halfSize(size / 2)
{}

void Camera::Update(const float &dt)
{
    currentPosition += (nextPosition - currentPosition) * moveSpeed * dt;
}

void Camera::SetPosition(const Vector2f &pos)
{
    currentPosition = pos;
    nextPosition = pos;
}

const Vector2f &Camera::GetPosition() const
{
    return currentPosition;
}

void Camera::SetNewPosition(const Vector2f &pos)
{
    nextPosition = pos;
}

void Camera::SetMoveSpeed(float val)
{
    if (val > 1)
        moveSpeed = 1.0f;
    else if (val < 0)
        moveSpeed = 0;
    else
        moveSpeed = val;
}

float Camera::GetMoveSpeed() const
{
    return moveSpeed;
}

void Camera::SetScale(float val)
{
    if (val > 0.1)
        scale = val;
    else
        scale = 0.1;
}

float Camera::GetScale() const
{
    return scale;
}

SDL_Rect Camera::GetRect() const
{
    return SDL_Rect {static_cast<int>(currentPosition.x),
                     static_cast<int>(currentPosition.y),
                     static_cast<int>(size.x),
                     static_cast<int>(size.y)};
}
