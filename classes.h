#pragma once

#include <iostream>
#include <string>

struct Vector2D{
    float x;
    float y;
};


class Entity
{
private:
    Vector2D curntPos;

public:
    Vector2D getPos(){
        return curntPos;
    }
};

class Enemy : public Entity
{
private:
    int health;
    int speed;
    int damage;
    bool isFlying;

public:

    Enemy()
    {
        health = 0;
        speed = 0;
        damage = 0;
        isFlying = false;
    }

    Enemy(int h, int s, int d, bool f)
    {
        health = h;
        speed = s;
        damage = d;
        isFlying = f;
    }

    int getHealth(){
        return health;
    }

    int getSpeed(){
        return speed;
    }

    int getDamage(){
        return damage;
    }

    bool checkFlight(){
        return isFlying;
    }

    virtual ~Enemy() = default;
};


class Tower : public Entity{




};

class BasicEnemy : public Enemy
{

public:
    BasicEnemy(int h, int s, int d, bool f) : Enemy(h, s, d, f) {}
};