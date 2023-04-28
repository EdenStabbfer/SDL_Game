//
// Created by kufuk on 26.04.2023.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "../Math/Math.h"
#include "../Graphics/Camera.h"
#include "../Graphics/Components/IEventCallable.h"
#include "../Graphics/Components/IUpdatable.h"
#include "../Graphics/Components/IDrawable.h"

#include "TileMap/TileMap.h"

class Player : public  IEventCallable, public IUpdatable, public IDrawable
{
public:
    Player(Camera& cam, const Vector2f& pos, const Vector2i& sz);

    void SetPosition(const Vector2f& pos);
    [[nodiscard]]
    const Vector2f& GetPosition() const;

    void SetSpeed(float val);
    [[nodiscard]]
    float GetSpeed() const;

    void SetSize(const Vector2u& s);
    [[nodiscard]]
    const Vector2u& GetSize() const;

    [[nodiscard]]
    SDL_Rect GetCollider() const;

    void Callback(SDL_Event& event, const Uint8* keyboard) override;

    void Update(const float& dt) override;

    void Render(SDL_Renderer* renderer, Camera* camera) override;

    void Move(const Vector2f& , const float& dt);

    void SetMap(TileMap& tileMap);

private:
    Vector2f position;
    Vector2u size;

    TileMap map;

    Vector2f moveDirection{0, 0};
    float speed {0};

    Camera& camera;
};


#endif //PLAYER_H
