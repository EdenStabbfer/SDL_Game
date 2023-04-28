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
    Camera(SDL_Window* wnd, const Vector2f& pos, const Vector2u& sz);

    void SetPosition(const Vector2f& pos);
    [[nodiscard]]
    const Vector2f& GetPosition() const;

    void SetSize(const Vector2u& s);
    void SetSize(const Vector2i& s);
    [[nodiscard]]
    Vector2u GetSize() const;

    [[nodiscard]]
    Vector2u GetHalfSize() const;

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
    Vector2i GetOffset() const;

    [[nodiscard]]
    SDL_Window* GetWindow() const;

    [[nodiscard]]
    int GetWindowWidth() const;
    [[nodiscard]]
    int GetWindowHeight() const;

    void Upscale();
    void Downscale();

    void Update(const float& dt) override;

    void Callback(SDL_Event& event, const Uint8* keyboard) override;

private:
    SDL_Window* window;

    Vector2f currentPosition;   // Позиция центра камеры
    Vector2f nextPosition;      // Позиция следования камеры

    Vector2u size {0};              // Размер камеры в пикселях
    Vector2u halfSize {0};          // Половина размера камеры
    Vector2f offset {0};

    float moveSpeed {1};        // Коэффициент перехода от старой позиции к новой (от 0 до 1)
    float scale {1};            // Коэффициент масштабирования изображения
};


#endif //CAMERA_H
