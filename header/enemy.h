#pragma once
#include "utilities.h"

class Enemy {
public:
    Enemy(float x, float y);
private:
    Vector2D position;
    float speed;
    int health;
};
