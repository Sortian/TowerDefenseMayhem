#pragma once
#include "grid.h"
#include "enemy.h"
#include "resourceManager.h"

class Game
{
private:
    Grid grid;
    ResourceManager rb;
    Enemy** enemies;
    int enemyCount;

public:
    Game();
    ~Game();
    void Draw();
    void PrintCoordinates();
};