#include "game.h"
#include "gameState.h"
#include "questions.h"

void Game::Update() {
    questions.Update(currentQuestion);
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
    questions.Draw(currentQuestion, currentState);
}