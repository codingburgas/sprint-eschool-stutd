#pragma once
#include "questions.h"
#include "gameState.h"

class Game {
public:
    void Draw();
    void Update();
    int currentQuestion = 0;
    GameState currentState = START_SCREEN;
private:
    questions questions;
    
};