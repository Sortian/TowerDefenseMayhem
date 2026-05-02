#include "raylib.h"
#include "classes.h"

using namespace std;

int main() {

    Enemy e;
    const int screenWidth = 1366;
    const int screenHeight = 768;




    InitWindow(screenWidth, screenHeight, "System-wide Raylib Test");

    Texture2D crate = LoadTexture("crate.png");

    SetTargetFPS(60);

    Vector2 position = { (float)screenWidth / 2 - (float)crate.width / 2, 
                          (float)screenHeight / 2 - (float)crate.height / 2 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        position.x += 0.1f;
        

        DrawTextureEx(crate,position,0.0f,0.2f,WHITE);

        string text = to_string(e.getHealth()); 
        DrawText(text.c_str() , screenWidth/2, screenHeight/2, 2+0, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
