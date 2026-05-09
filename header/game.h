#pragma once
#include "grid.h"
#include "enemy.h"
#include "resourceManager.h"

class Game
{
private:
    Grid grid;
    ResourceManager rb;
    Enemy **enemies;
    int enemyCount;
    Texture2D bg;

    int playerHealth;
    int playerGold;

    float spawnTimer;
    float spawnInterval;
    int currentEnemyIndex;

public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void PrintCoordinates();
    void TakeDamage(int dmg);

    void StartWave1();
};