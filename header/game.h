#pragma once
#include "grid.h"
#include "enemy.h"
#include "tower.h"
#include "button.h"
#include "resourceManager.h"

class Game
{
private:
    Grid grid;
    ResourceManager rb;

    Enemy **enemies;
    Tower **towers;

    int enemyCount;
    int towerCount;

    Texture2D bg;

    int playerHealth;
    int playerGold;
    int WaveNumber;

    float spawnTimer;
    float spawnInterval;
    int currentEnemyIndex;

    bool TowerUIstate;

    Button *towerUI;
    int buttonCount;
    bool checkValidCost;

    string currentTower;


public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void PrintCoordinates();
    void TakeDamage(int dmg);

    
    void DrawStatusText();
    void DrawButtonLabel(const Button &btn);
    void LoadUI();

    bool CheckUIClick(Button &btn);
    bool CheckGridClick(float x, float y);

    void resetUIbuttons();
    Vector2D DetermineClickCell();

    void setCurrentTower(string clickedButtonLabel);
    void increaseTowerCapacity();
    void PlaceTower(string tower, float x, float y);

    void StartWave1();
    
};