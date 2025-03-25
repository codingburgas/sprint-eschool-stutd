#include "game.h"
#include "gameState.h"
#include "questions.h"

void Game::Update() {
    if (currentState == START_SCREEN) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            Rectangle startButtonRect = { 260, 185, 280, 105 };

            if (CheckCollisionPointRec(mousePosition, startButtonRect)) {
                currentState = PLAYING;
                currentQuestion = 0;
            }
        }
    }
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);

    if (currentState == START_SCREEN) {
        DrawTexture(startButtonImage, 260, 185, WHITE);
    }
}

void Game::loadAssets() {
    background = LoadTexture("assets/background.png");
    startButtonImage = LoadTexture("assets/Start.png");
}

