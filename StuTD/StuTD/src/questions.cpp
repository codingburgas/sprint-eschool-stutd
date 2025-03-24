#include "pch.h"
#include "questions.h"
#include "gameState.h"
#include "game.h"

questions::questions() {
    questionsText = {
        { "In which year was Slav-Bulgarian History written?", "A. 1758", "B. 1760", "C. 1762" },
        { "What was the main purpose of Slav-Bulgarian History?", "A. To entertain readers with fictional stories", "B. To encourage Bulgarians to take pride in their history", "C. To promote trade among Slavic nations" },
        { "Where was Slav-Bulgarian History written?", "A. The Rila Monastery", "B. The Zograf Monastery", "C. The Bachkovo Monastery" },
        { "Who is considered the author of Slav-Bulgarian History?", "A. Neofit Rilski", "B. Ivan Vazov", "C. Paisiy Hilendarski" },
        { "Which of the following statements best describes the main message of Slav-Bulgarian History?", "A. Bulgarians should forget their past and embrace modernization", "B. Bulgarians have a glorious history and should not be ashamed of their identity", "C. The Bulgarian language should be replaced with Greek" },
        { "Which historical periods does Slav-Bulgarian History primarily cover?", "A. The Ottoman Empire and Bulgarian Revival", "B. The ancient Thracians and Romans", "C. The early Bulgarian state and medieval Bulgarian empires" },
        { "How did Slav-Bulgarian History influence the Bulgarian people?", "A. It encouraged them to abandon their traditions", "B. It played a key role in awakening national consciousness", "C. It promoted Greek culture over Bulgarian culture" },
        { "In what language was Slav-Bulgarian History originally written?", "A. Modern Bulgarian", "B. Old Church Slavonic", "C. Greek" },
        { "What phrase is often associated with Paisiy Hilendarski's call to Bulgarians?", "A. Read and know!", "B. Protect the Bulgarian!", "C. Oh, foolish and mad people!" },
        { "What is considered the main goal of Slav-Bulgarian History?", "A. To entertain the Bulgarian elite", "B. To create a guide for Bulgarian merchants", "C. To remind Bulgarians of their proud history and inspire unity" }
    };
    background = LoadTexture("assets/background.png");
    LoadStartButtonImage();
}

void questions::LoadStartButtonImage() {
    startButtonImage = LoadTexture("assets/Start.png");
}

void questions::Update(int& currentQuestion) {
    if (IsKeyPressed(KEY_SPACE)) {
        if (currentQuestion < questionsText.size() - 1) {
            currentQuestion++;
        }
        else {  
            currentQuestion = 0;
        }
    }
}

void questions::Draw(int currentQuestion, GameState& currentState) {
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);

    if (currentState == START_SCREEN) {
        DrawTexture(startButtonImage, 260, 185, WHITE);
    }
    else if (currentState == PLAYING) {
        DrawText(questionsText[currentQuestion][0].c_str(), 100, 50, 20, BLACK);
        for (int i = 1; i < questionsText[currentQuestion].size(); i++) {
            DrawText(questionsText[currentQuestion][i].c_str(), 100, 100 + i * 30, 20, BLACK);
        }
    }
}
