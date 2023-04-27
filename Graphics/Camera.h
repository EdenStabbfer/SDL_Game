//
// Created by kufuk on 26.04.2023.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

#include "../Math/Math.h"
#include "Components/IUpdatable.h"
#include "Components/IEventCallable.h"

#define SCALE_COEFFICIENT 0.1
#define MAX_SCALE 4.0
#define MIN_SCALE 0.1

class Camera : public IUpdatable, public IEventCallable
{
public:
    Camera(const Vector2f& pos, const Vector2u& sz);

    void SetPosition(const Vector2f& pos);
    [[nodiscard]]
    const Vector2f& GetPosition() const;

    void SetSize(const Vector2u& s);
    void SetSize(const Vector2i& s);
    [[nodiscard]]
    Vector2u GetSize() const;

    void SetNextPosition(const Vector2f& pos);

    void SetMoveSpeed(float val);
    [[nodiscard]]
    float GetMoveSpeed() const;

    void SetScale(float val);
    [[nodiscard]]
    float GetScale() const;

    [[nodiscard]]
    SDL_Rect GetRect() const;

    [[nodiscard]]
    Vector2f GetOffset() const;

    void Upscale();
    void Downscale();

    void Update(const float& dt) override;

    void Callback(SDL_Event& event, const Uint8* keyboard) override;

private:
    Vector2f currentPosition;   // Позиция центра камеры
    Vector2f nextPosition;      // Позиция следования камеры

    Vector2u size{0};              // Размер камеры в пикселях
    Vector2u halfSize{0};          // Половина размера камеры

    float moveSpeed {1};        // Коэффициент перехода от старой позиции к новой (от 0 до 1)
    float scale {1};            // Коэффициент масштабирования изображения
};


#endif //CAMERA_H
