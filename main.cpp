#include <raylib.h>
#include "game.h"

using namespace std;

int main()
{

    const int screenWidth = 1360;
    const int screenHeight = 760;

    InitWindow(screenWidth, screenHeight, "Tower Defense Mayhem");
    Game game;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            
            Vector2 mousePos = GetMousePosition();

            
            cout << "Mouse Clicked at: X: " << mousePos.x << " | Y: " << mousePos.y << endl;
        }


        
        game.Draw();
        game.Update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
