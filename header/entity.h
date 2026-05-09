#pragma once
#include "utilities.h"


class ResourceManager;

class Entity
{
private:
    Vector2D position;

public:
    Entity(){position = Vector2D(0, 0);}
    Entity(float x, float y) : position(x, y) {}
    Entity(Vector2D pos) : position(pos) {}


    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void draw(ResourceManager& rb) = 0;
    virtual Vector2D getPos() const { return position; }
    void setPos(Vector2D pos) { position = pos; }
};