#pragma once
#include "pch.h"
#include "gameState.h"

class questions {
public:
    questions();
    void Draw(int currentQuestion, GameState& currentState);
    void Update(int& currentQuestion);
    void LoadStartButtonImage();
    vector<vector<string>> questionsText;
    vector<int> correctAnswers;
    Texture2D background;
    Texture2D startButtonImage;
};