#include "pch.h"
#include "game.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Game game;
    SetTargetFPS(60);
    game.loadAssets();


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        game.Update();
        game.Draw();
        EndDrawing();
    }
}