#include <raylib.h>
#include "game.h"

using namespace std;

int main() {

    const int screenWidth = 1360;
    const int screenHeight = 760;

    Game game;
    
    InitWindow(screenWidth, screenHeight, "Tower Defense Mayhem");
\
    SetTargetFPS(60);
    game.PrintCoordinates();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        game.Draw();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
