#include "game.h"
#include "pch.h"
#include "gameState.h"
#include "questions.h"
#include <array>
#include <vector>
#include <format>

constexpr int fontSize = 20;
void Game::Update() {
    if (currentState == START_SCREEN) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            Rectangle startButtonRect = { 260, 185, 280, 105 };
            if (CheckCollisionPointRec(mousePosition, startButtonRect)) {
                if (questions.empty())
                    return;

                currentState = PLAYING;
                currentQuestion = 0;
            }
        }
    }

    if (currentState == PLAYING) {

        try {

            Vector2 mousePos = GetMousePosition();


            std::array<int, 3> widths = {
                            MeasureText(questions[currentQuestion].answer1.c_str(), fontSize),
                            MeasureText(questions[currentQuestion].answer2.c_str(), fontSize),
                            MeasureText(questions[currentQuestion].answer3.c_str(), fontSize),
            };


            std::array<Rectangle, 3> rectangles = {
                Rectangle{150, 205, (float)widths[0], (float)fontSize},
                Rectangle{150, 275, (float)widths[1], (float)fontSize},
                Rectangle{150, 345, (float)widths[2], (float)fontSize}
            };

            auto selectAnswer = [&](int answerIndex, std::string answerText) {
                questions[currentQuestion].chosenAnswer = answerText;
                std::cout << std::format("selected question: {} ", questions[currentQuestion].chosenAnswer) << std::endl;
                if (currentQuestion + 1 < questions.size())
                    currentQuestion++;
                else {
                    std::cout << "No more questions." << std::endl;
                    currentState = GAME_OVER;
                }

                };

            if (CheckCollisionPointRec(mousePos, rectangles[0]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                selectAnswer(1, questions[currentQuestion].answer1);

            if (CheckCollisionPointRec(mousePos, rectangles[1]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                selectAnswer(2, questions[currentQuestion].answer2);

            if (CheckCollisionPointRec(mousePos, rectangles[2]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                selectAnswer(3, questions[currentQuestion].answer3);

        }
        catch (const exception& e) {
            std::cerr << std::format("error: {}", e.what()) << std::endl;
        }
    }
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);

    if (currentState == START_SCREEN) {
        DrawTexture(startButtonImage, 260, 185, WHITE);
    }

    if (currentState == PLAYING && currentQuestion < questions.size()) {
        DrawText(questions[currentQuestion].question.c_str(), 150, 135, 20, BLACK);
        DrawText(questions[currentQuestion].answer1.c_str(), 150, 205, 20, BLACK);
        DrawText(questions[currentQuestion].answer2.c_str(), 150, 275, 20, BLACK);
        DrawText(questions[currentQuestion].answer3.c_str(), 150, 345, 20, BLACK);
    }
    if (currentState == GAME_OVER) {
        DrawText("Game Over", 150, 135, 20, BLACK);
    }
}

void Game::loadAssets() {
    background = LoadTexture("assets/background.png");
    startButtonImage = LoadTexture("assets/Start.png");
    questions = questionsRepo.getQuestions();
}
