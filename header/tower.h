#pragma once
#include "entity.h"


class Tower : public Entity
{

    int cost;
    int damage;
    double attackRadius;

    int state; // 0 for looking for enemy 1 for shooting a specific enemy

    float shootTimer;
    float shootInterval;
    int currentEnemyIndex;

public:
    Tower()
    {
        cost = 0;
        damage = 0;
        attackRadius = 0;

        state = 0;

        shootTimer = 0.0f;
        shootInterval = 0.0f;
        currentEnemyIndex = -1;
    }

    Tower(int c, int d, double r, int s, float sT, float sI, int eI)
    {
        cost = c;
        damage = d;
        attackRadius = r;

        state = s;

        shootTimer = sT;
        shootInterval = sI;
        currentEnemyIndex = eI;
    }

    int getCost() {return cost;}

    virtual void targetEnemy() = 0;
    virtual void draw(ResourceManager &rb) override = 0;
    virtual void  update() override = 0;
};

class CannonTower : public Tower
{

public:
    CannonTower() : Tower(100, 10, 200, 0, 0.0f, 1.0f, -1)
    {
    }

    void targetEnemy() override;
     void draw(ResourceManager &rb) override;
    void update() override;
};

class SniperTower : public Tower
{
public:
    SniperTower() : Tower(200, 30, 300, 0, 0.0f, 2.5f, -1)
    {
    }

    void targetEnemy() override;
    void draw(ResourceManager &rb) override;
    void update() override;
};

class MachineGunTower : public Tower
{
public:
    MachineGunTower() : Tower(500, 5, 200, 0, 0.0f, 0.5f, -1)
    {
    }

    void targetEnemy() override;
    void draw(ResourceManager &rb) override;
    void update() override;
};

class SlowTower : public Tower
{
    int slowEffect;
public:
    SlowTower() : Tower(1000, 5, 200, 0, 0.0f, 5.0f, -1)
    {slowEffect = 20;
    }

    void targetEnemy() override;
    void draw(ResourceManager &rb) override;
    void update() override;
};


