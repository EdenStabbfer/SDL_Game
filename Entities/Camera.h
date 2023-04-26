//
// Created by kufuk on 26.04.2023.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

#include "../Math/Math.h"


class Camera
{
public:
    Camera(const Vector2f& pos, const Vector2f& size);

    void SetPosition(const Vector2f& pos);
    [[nodiscard]]
    const Vector2f& GetPosition() const;

    void SetNewPosition(const Vector2f& pos);

    void SetMoveSpeed(float val);
    [[nodiscard]]
    float GetMoveSpeed() const;

    void SetScale(float val);
    [[nodiscard]]
    float GetScale() const;

    [[nodiscard]]
    SDL_Rect GetRect() const;

    void Update(const float& dt);

private:
    Vector2f currentPosition;   // Позиция центра камеры
    Vector2f nextPosition;      // Позиция следования камеры
    Vector2f size;              // Размер камеры в пикселях
    Vector2f halfSize;          // Половина размера камеры

    float moveSpeed {1};        // Коэффициент перехода от старой позиции к новой (от 0 до 1)
    float scale {1};            // Коэффициент масштабирования изображения
};


#endif //CAMERA_H
