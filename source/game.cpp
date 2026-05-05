#include "game.h"

void Game::Draw() {
   
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    grid.drawGrid();
    
    
    EndDrawing();
}

void Game::PrintCoordinates() {
    for(int i = 0; i < grid_size; i++){
        for(int j = 0; j < grid_size; j++){
            grid.printCordinates(i, j);
        }
    }
    
}