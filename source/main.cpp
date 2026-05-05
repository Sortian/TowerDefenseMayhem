#include "raylib.h"
#include "classes.h"

using namespace std;

int main() {

    Enemy e;
    const int screenWidth = 1366;
    const int screenHeight = 768;




    InitWindow(screenWidth, screenHeight, "System-wide Raylib Test");

    Texture2D basic = LoadTexture("assets/enemy_1.png");
    Texture2D heavy = LoadTexture("assets/enemy_tank.png");
    Texture2D fast = LoadTexture("assets/enemy_fast.png");
    Texture2D fly = LoadTexture("assets/enemy_fly.png");
    

    SetTargetFPS(60);

    Vector2 position1 = { (float)screenWidth / 2 - (float)basic.width / 2, 
                          (float)screenHeight / 2 - (float)basic.height / 2 };

    Vector2 position2 = { (float)screenWidth / 2 - (float)basic.width / 2, 
                          (float)screenHeight / 2 - (float)basic.height / 2 };

    Vector2 position3 = { (float)screenWidth / 2 - (float)basic.width / 2, 
                          (float)screenHeight / 2 - (float)basic.height / 2 };


    Vector2 position4 = { (float)screenWidth / 2 - (float)basic.width / 2, 
                          (float)screenHeight / 2 - (float)basic.height / 2 };


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        position1.x += 0.1f;
        position2.x += 0.05f;
        position3.x += 0.2f;
        position4.x += 0.15f;
        

        DrawTextureEx(basic,position1,0.0f,0.2f,WHITE);
        DrawTextureEx(heavy,position2,0.0f,0.3f,WHITE);
        DrawTextureEx(fast,position3,0.0f,0.2f,WHITE);
        DrawTextureEx(fly,position4,0.0f,0.2f,WHITE);

        string text = to_string(e.getHealth()); 
        DrawText(text.c_str() , screenWidth/2, screenHeight/2, 2+0, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
