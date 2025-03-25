#pragma once
#include "questions.h"
#include "gameState.h"

class Game {
public:
    void loadAssets();
    void Draw();
    void Update();
    int currentQuestion = 0;
    GameState currentState = START_SCREEN;

private:
    Texture2D background;
    Texture2D startButtonImage;
};