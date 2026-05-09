#pragma once
#include "entity.h"



class Enemy : public Entity
{
private:
    Vector2D direction;
    float speed;
    int health;
    int damage;


    int turn;
    bool isSpawned;
    

public:
    Enemy() : Entity(0, 210)
    {
        direction.x = 1;
        direction.y = 0;
        speed = 2.0f;
        health = 100;
        damage = 10;
        turn = 1;
        isSpawned = false;
    }
    Enemy(float x, float y) : Entity(x, y)
    {
        direction.x = 1;
        direction.y = 0;
        speed = 1.0f;
        health = 100;
        damage = 10;
        turn = 1;
        isSpawned = false;
    }
    Enemy(float x, float y, float speed, int health, int damage) : Entity(x, y), speed(speed), health(health), damage(damage)
    {
        direction.x = 1;
        direction.y = 0;
        turn = 1;
        isSpawned = false;
    }

    void setSpeed(float spd) { speed = spd; }
    float getSpeed() const { return speed; }

    int getHealth() const { return health; }
    void setHealth(int hp) { health = hp; }

    int getDamage() const { return damage; }

    void setDirection(float x, float y)
    {
        direction.x = x;
        direction.y = y;
    }
    Vector2D getDirection() const { return direction; }

    void setTurn(int t) { turn = t; }
    int getTurn() { return turn; }

    bool checkSpawnStatus() const { return isSpawned;}
    void setSpawnStatus(bool a)  { isSpawned = a;}

    void draw(ResourceManager &rb) override;
    void update() override;


};

class FastEnemy : public Enemy
{
public:
    FastEnemy() : Enemy(0, 230, 4.0f, 80, 15) {}
    FastEnemy(float x, float y) : Enemy(x, y, 4.0f, 80, 15)
    {
    }
    void draw(ResourceManager &rb) override;
    void update() override;
};

class TankEnemy : public Enemy
{
    Texture2D shadowTexture;
public:
    TankEnemy() : Enemy(0, 200, 1.0f, 200, 15) {}
    TankEnemy(float x, float y) : Enemy(x, y, 1.0f, 200, 15) {}
    void draw(ResourceManager &rb) override;
    void update() override;
};

class FlyEnemy : public Enemy
{

public:
    FlyEnemy() : Enemy(0, 180, 1.5f, 200, 15) {}
    FlyEnemy(float x, float y) : Enemy(x, y, 1.0f, 200, 15) {}
    void draw(ResourceManager &rb) override;
    void update() override;
};
