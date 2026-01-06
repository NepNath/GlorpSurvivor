#pragma once

#include <SFML/Graphics.hpp>
#include <game_export.h>

namespace game::main
{
struct GAME_EXPORT Vector2d
{
    float x;
    float y;
    Vector2d()
        : x(0.0f)
        , y(0.0f)
    {
    }

    Vector2d(float x, float y)
        : x(x)
        , y(y)
    {
    }
};

struct GAME_EXPORT Mouvement
{
    Vector2d direction;
    float speed;
    Mouvement()
        : direction(0, 0)
        , speed(0)
    {
    }
    Mouvement(Vector2d dir, float spd)
        : direction(dir)
        , speed(spd)
    {
    }
};

struct GAME_EXPORT Projectile
{
    Vector2d position;
    sf::CircleShape shape;
    Projectile(Vector2d pos, float size)
        : position(pos)
        , shape(size)
    {
        shape.setPosition(pos.x, pos.y);
        shape.setFillColor(sf::Color::Red);
    }
};

GAME_EXPORT int GenerateRandomInt(int min, int max);

GAME_EXPORT int run();
} // namespace game::main