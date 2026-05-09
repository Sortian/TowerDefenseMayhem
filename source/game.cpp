#include "game.h"




Game::Game() {

    rb.loadResources();
    enemyCount = 10;
    enemies = new Enemy*[enemyCount];

    for(int i = 0; i < enemyCount; i++){
        enemies[i] = new FastEnemy();
    }

  
}

Game::~Game() {
    rb.unloadResources();
    for (int i = 0; i < enemyCount; i++) {
        delete enemies[i];
    }
    delete[] enemies;
}

void Game::Draw() {
   
    
    BeginDrawing();
    ClearBackground(RAYWHITE);

      grid.drawGrid();
    for (int i = 0; i < enemyCount; i++) {
        
        enemies[i]->draw(rb);
        enemies[i]->update();
    }

  
    
    
    EndDrawing();
}

void Game::PrintCoordinates() {
    const int grid_count = 10;
    for(int i = 0; i < grid_count; i++){
        for(int j = 0; j < grid_count; j++){
            grid.printCordinates(i, j);
        }
    }
    
}