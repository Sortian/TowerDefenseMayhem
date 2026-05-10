#include "game.h"

Game::Game()
{

    rb.loadResources();

    spawnTimer = 0.0f;
    spawnInterval = 1.0f;
    currentEnemyIndex = 0;

    WaveNumber = 1;
    playerHealth = 50;
    playerGold = 500;

    enemyCount = 0;
    enemies = nullptr;

    bg = rb.getResource("bg_1");

    TowerUIstate = 0;

    buttonCount = 4;
    LoadUI();

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

    delete[] towerUI;
}

void Game::StartWave1()
{

    enemyCount = 4;

    enemies = new Enemy *[enemyCount];

    enemies[0] = new BasicEnemy();
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

    // enemy spawning

    spawnTimer += GetFrameTime();

    if (spawnTimer >= spawnInterval && currentEnemyIndex < enemyCount)
    {

        enemies[currentEnemyIndex]->setSpawnStatus(true);

        currentEnemyIndex++;
        spawnTimer = 0.0f;
    }

    // enemies update

    for (int i = 0; i < enemyCount; i++)
    {
        if (enemies[i] == nullptr)
            continue;
        if (!(enemies[i]->checkSpawnStatus()))
            continue;

        // enemies reach the end of the screen
        if (enemies[i]->getPos().x > 1250)
        {
            int damage = enemies[i]->getDamage();
            TakeDamage(damage);

            enemies[i] = nullptr;
            continue;
        }

        enemies[i]->update();
    }

    // User Interface

    for (int i = 0; i < buttonCount; i++)
    {
        if (CheckUIClick(towerUI[i]))
        {
            TowerUIstate = 1;
        }
    }
}

void Game::DrawButtonLabel(const Button &btn)
{

    const char *text = btn.label.c_str();
    int fontsize = 10;

    Color color = WHITE;

    int textWidth = MeasureText(text, fontsize);

    int textX = (int)(btn.rect.x + (btn.rect.width / 2) - (textWidth / 2));
    int textY = (int)(btn.rect.y + (btn.rect.height / 2) - (fontsize / 2));

    DrawText(text, textX, textY, fontsize, color);
}

void Game::Draw()
{

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexture(bg, 0, 0, WHITE);

    DrawText(TextFormat("HEALTH: %i", playerHealth), 20, 10, 30, RED);
    DrawText(TextFormat("GOLD: %i", playerGold), 220, 10, 30, GOLD);
    DrawText(TextFormat("Wave: %i", WaveNumber), 400, 10, 30, BLUE);

    grid.drawGrid();

    for (int i = 0; i < enemyCount; i++)
    {
        if (enemies[i] != nullptr && enemies[i]->checkSpawnStatus())
            enemies[i]->draw(rb);
    }

    for (int i = 0; i < buttonCount; i++)
    {

        Color col = towerUI[i].isClicked ? GOLD : (towerUI[i].isHovered ? LIGHTGRAY : GRAY);
        DrawRectangleRec(towerUI[i].rect, col);
        DrawButtonLabel(towerUI[i]);
    }
    DrawStatusText();

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

void Game::LoadUI()
{

    towerUI = new Button[buttonCount];

    float UIstartX = 800;
    float UIstartY = 5;
    float UIwidth = 120;
    float UIheight = 40;
    float UIgap = 10;
    string names[] = {"Cannon $100", "Sniper $200", "Machine $300", "Slow $600"};
    int costs[] = {100, 200, 300, 600};

    for (int i = 0; i < buttonCount; i++)
    {
        towerUI[i].rect = {UIstartX + (i * (UIwidth + UIgap)), UIstartY, UIwidth, UIheight};
        towerUI[i].label = names[i];
        towerUI[i].cost = costs[i];
        towerUI[i].isHovered = false;
        towerUI[i].isClicked = false;
    }
}

bool Game::CheckUIClick(Button &btn)
{

    if (CheckCollisionPointRec(GetMousePosition(), btn.rect))
    {
        btn.isHovered = true;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            for (int i = 0; i < buttonCount; i++)
            {
                if (btn.label == towerUI[i].label)
                    continue;
                towerUI[i].isClicked = false;
            }

            btn.isClicked = true;
            return true;
        }
        else
            btn.isHovered = false;
    }
    return false;
}

void Game::DrawStatusText()
{

    string statusText = "null";
    if (TowerUIstate == 0)
    {
        statusText = "Enemies are approaching...";
    }
    else if (TowerUIstate == 1)
    {
        statusText = "Place the tower in a valid tile.";
    }

    DrawText(statusText.c_str(),10,650,40,WHITE);
}