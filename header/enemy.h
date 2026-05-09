#pragma once
#include "entity.h"  

class ResourceManager;

class Enemy : public Entity
{
private:
    Vector2D direction;
    float speed;

    int maxHealth;
    int currentHealth;
    int damage;

    int turn;
    bool isSpawned;

public:
    Enemy() : Entity(0, 0)
    {
        direction.x = 1;
        direction.y = 0;
        speed = 0.0f;
        maxHealth = 0;
        currentHealth = maxHealth;
        damage = 0;
        turn = 1;
        isSpawned = false;
    }
    Enemy(float x, float y, float speed, int maxHealth, int damage) : Entity(x, y), speed(speed), maxHealth(maxHealth), damage(damage)
    {
        direction.x = 1;
        direction.y = 0;
        turn = 1;
        isSpawned = false;
    }

    void setSpeed(float spd) { speed = spd; }
    float getSpeed() const { return speed; }

    int getmaxHealth() const { return maxHealth; }
    void setmaxHealth(int hp) { maxHealth = hp; }

    int getDamage() const { return damage; }

    void setDirection(float x, float y)
    {
        direction.x = x;
        direction.y = y;
    }
    Vector2D getDirection() const { return direction; }

    void setTurn(int t) { turn = t; }
    int getTurn() { return turn; }

    bool checkSpawnStatus() const { return isSpawned; }
    void setSpawnStatus(bool a) { isSpawned = a; }

    virtual void draw(ResourceManager &rb) override = 0;
    virtual void  update() override = 0;
};

class BasicEnemy : public Enemy
{

public:
    BasicEnemy() : Enemy(0, 210, 2.0f, 100, 15) {}
    BasicEnemy(float x, float y) : Enemy(x, y, 2.0f, 100, 15)
    {
    }
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
