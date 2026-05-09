#pragma once
#include "entity.h"

class Enemy : public Entity {
private:
    float speed;
    int health;
    int damage;

public:
    Enemy();
    Enemy(float x, float y) : Entity(x, y) { speed = 1.0f; health = 100; damage = 10; }
    Enemy(float x, float y, float speed, int health, int damage) : Entity(x, y), speed(speed), health(health), damage(damage) {}

    void setSpeed(float spd) { speed = spd; }
    float getSpeed() const { return speed; }

    int getHealth() const { return health; }
    void setHealth(int hp) { health = hp; }

    int getDamage() const { return damage; }


    

    void draw(ResourceManager &rb) override;
    void update() override;
};


class FastEnemy : public Enemy {
public:
    FastEnemy() : Enemy(300, 300, 2.0f, 80, 15) {}
    FastEnemy(float x, float y) : Enemy(x, y, 2.0f, 80, 15) {
    }
    void draw(ResourceManager& rb) override;

};