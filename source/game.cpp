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

    towerCount = 0;
    towers = nullptr;
    currentTower = "null";

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

    if (towers != nullptr)
    {
        for (int i = 0; i < towerCount; i++)
        {
            delete towers[i];
        }
        delete[] towers;

        towers = nullptr;
    }

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

    // GridCheck
    if (TowerUIstate == 1)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2D mbPos = GetMousePosition();

            if (CheckGridClick(mbPos.x, mbPos.y))
            {
                resetUIbuttons();
                TowerUIstate = 0;

                PlaceTower(currentTower, mbPos.x, mbPos.y);
            }
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

    for (int i = 0; i < towerCount; i++)
    {
        if (towers[i] != nullptr)
            towers[i]->draw(rb);
    }

    for (int i = 0; i < buttonCount; i++)
    {

        Color col = GRAY;

        if (towerUI[i].isClicked)
            col = GOLD;
        else if (towerUI[i].isHovered)
            col = LIGHTGRAY;

        DrawRectangleRec(towerUI[i].rect, col);
        DrawButtonLabel(towerUI[i]);
    }
    DrawStatusText();
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

void Game::setCurrentTower(string clickedButtonLabel)
{

    if (clickedButtonLabel == "Cannon $100")
        currentTower = "cannon";
    else if (clickedButtonLabel == "Sniper $200")
        currentTower = "sniper";
    else if (clickedButtonLabel == "Machine $500")
        currentTower = "machine";
    else if (clickedButtonLabel == "Slow $600")
        currentTower = "slow";
    else
        currentTower = "error";
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

            setCurrentTower(btn.label);

            return true;
        }
    }
    else
    {
        btn.isHovered = false;
    }
    return false;
}

bool Game::CheckGridClick(float x, float y)
{
    bool valid = false;
    Vector2D mbPos = {x, y};

    if (CheckCollisionPointRec(mbPos, grid.getgridRect()))
    {
        Vector2D cell = grid.returnCell(mbPos.x, mbPos.y);

        valid = true;
    }
    return valid;
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

    DrawText(statusText.c_str(), 10, 650, 40, WHITE);
}

void Game::resetUIbuttons()
{

    for (int i = 0; i < buttonCount; i++)
    {
        towerUI[i].isClicked = false;
    }
}

void Game::increaseTowerCapacity()
{
    Tower **newArr = new Tower *[towerCount + 1];
    if (towers != nullptr)
    {
        for (int i = 0; i < towerCount; i++)
            newArr[i] = towers[i];
    }

    towerCount++;

    delete[] towers;

    towers = newArr;
}

void Game::PlaceTower(string tower, float x, float y)
{
    cout << "place tower x: " << x << "y: " << y << endl;

    cout << "placeTower called" << endl;
    increaseTowerCapacity();

    Vector2D cellCount = grid.returnCell(x,y);

    cout << "cell count x: " << cellCount.x << "  " << cellCount.y << endl;

    Vector2D gridCords = grid.getCordinates((int)cellCount.x, (int)cellCount.y);

    cout << "gridCords x: " << gridCords.x << "  " << gridCords.y << endl;

    int towerIndex = towerCount - 1;

    if (tower == "cannon")
    {
        towers[towerIndex] = new CannonTower();
    }
    else if (tower == "sniper")
    {
        towers[towerIndex] = new SniperTower();
    }
    else if (tower == "machine")
    {
        towers[towerIndex] = new MachineGunTower();
    }
    else if (tower == "slow")
    {
        towers[towerIndex] = new SlowTower();
    }
    else
    {
        cout << "error in place tower" << endl;
    }

    towers[towerIndex]->setPos(gridCords);
}