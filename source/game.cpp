#include "game.h"

Game::Game()
{

    rb.loadResources();

    spawnTimer = 0.0f;
    spawnInterval = 1.0f;
    currentEnemyIndex = 0;

    playerHealth = 50;
    playerGold = 500;

    // Enemy

    enemyCount = 0;
    enemies = nullptr;

    // Background
    bg = rb.getResource("bg_1");



    StartWave1();
}

Game::~Game()
{
    rb.unloadResources();
    for (int i = 0; i < enemyCount; i++)
    {
        delete enemies[i];
    }
    delete[] enemies;
}

void Game::StartWave1()
{

    enemyCount = 4;

    enemies = new Enemy *[enemyCount];

    enemies[0] = new Enemy();
    enemies[1] = new FastEnemy();
    enemies[2] = new TankEnemy();
    enemies[3] = new FlyEnemy();
}

void Game::TakeDamage(int dmg)
{

    playerHealth -= dmg;
}

void Game::Update()
{

    spawnTimer += GetFrameTime();

    if (spawnTimer >= spawnInterval && currentEnemyIndex < enemyCount)
    {

        enemies[currentEnemyIndex]->setSpawnStatus(true);

        currentEnemyIndex++;
        spawnTimer = 0.0f;
    }

    for (int i = 0; i < enemyCount; i++)
    {
        if (enemies[i] == nullptr)
            continue;
        if (!(enemies[i]->checkSpawnStatus()))
            continue;

        // enemies reach the end of the screen
        if (enemies[i]->getPos().x > 1200)
        {
            int damage = enemies[i]->getDamage();
            TakeDamage(damage);

            enemies[i] = nullptr;
            continue;
        }

        enemies[i]->update();
    }
}

void Game::Draw()
{

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexture(bg, 0, 0, WHITE);
    DrawText(TextFormat("HEALTH: %i", playerHealth), 20, 20, 30, RED);
    DrawText(TextFormat("GOLD: %i", playerGold), 220, 20, 30, GOLD);

    grid.drawGrid();
    for (int i = 0; i < enemyCount; i++)
    {
        if (enemies[i] != nullptr && enemies[i]->checkSpawnStatus())
            enemies[i]->draw(rb);
    }

    EndDrawing();
}

void Game::PrintCoordinates()
{
    const int grid_count = 10;
    for (int i = 0; i < grid_count; i++)
    {
        for (int j = 0; j < grid_count; j++)
        {
            grid.printCordinates(i, j);
        }
    }
}