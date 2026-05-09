#include <raylib.h>
#include "game.h"

using namespace std;

int main() {

    const int screenWidth = 1360;
    const int screenHeight = 760;

    
    
    InitWindow(screenWidth, screenHeight, "Tower Defense Mayhem");
    Game game;

    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        game.Draw();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
