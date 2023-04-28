//
// Created by kufuk on 26.04.2023.
//

#include "Camera.h"
#include <iostream>

Camera::Camera(SDL_Window* wnd, const Vector2f &pos, const Vector2u& sz) :
        window(wnd),
        currentPosition(pos),
        nextPosition(pos),
        size(sz),
        halfSize(sz / 2)
{}

void Camera::Update(const float &dt)
{
    currentPosition += (nextPosition - currentPosition) * moveSpeed * dt;

    offset = (Vector2f)halfSize / scale - currentPosition ;
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

void Camera::SetNextPosition(const Vector2f &pos)
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
    if (val > MIN_SCALE)
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
    return SDL_Rect {static_cast<int>(currentPosition.x - halfSize.x),
                     static_cast<int>(currentPosition.y - halfSize.y),
                     static_cast<int>(size.x),
                     static_cast<int>(size.y)};
}

Vector2i Camera::GetOffset() const
{
    return (Vector2i)offset;
}

void Camera::SetSize(const Vector2u &s)
{
        size = s;
        halfSize = s / 2;
}

void Camera::SetSize(const Vector2i &s)
{
    if (s.x > 0)
        size.x = s.x;
    else
        size.x = 0;
    if (s.y > 0)
        size.y = s.y;
    else
        size.y = 0;
}

Vector2u Camera::GetSize() const
{
    return (Vector2f)size / scale;
}

Vector2u Camera::GetHalfSize() const
{
    return (Vector2f)halfSize / scale;
}

SDL_Window *Camera::GetWindow() const
{
    return window;
}

void Camera::Upscale()
{
    if (scale < MAX_SCALE - SCALE_COEFFICIENT)
        scale += SCALE_COEFFICIENT;
}

void Camera::Downscale()
{
    if (scale > MIN_SCALE)
        scale -= SCALE_COEFFICIENT;
}

void Camera::Callback(SDL_Event &event, const Uint8 *keyboard)
{
    if (event.type == SDL_MOUSEWHEEL)
    {
        if(event.wheel.y > 0)
            {
                Upscale();
            }
        else if(event.wheel.y < 0)
            {
                Downscale();
            }
    }
}

int Camera::GetWindowWidth() const
{
    int w;
    SDL_GetWindowSizeInPixels(window, &w, nullptr);
    return w;
}

int Camera::GetWindowHeight() const
{
    int h;
    SDL_GetWindowSizeInPixels(window, nullptr, &h);
    return h;
}
