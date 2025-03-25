#include "game.h"
#include "pch.h"
#include "gameState.h"
#include "questions.h"

void Game::Update() {
    if (currentState == START_SCREEN) {
        Rectangle startButtonRect = { 260, 185, 280, 105 };
        Vector2 mousePosition = GetMousePosition();
        if (CheckCollisionPointRec(mousePosition, startButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            currentState = PLAYING;
            currentQuestion = 0;
        }
    }

    if (currentState == PLAYING) {
        // Define rectangles for each answer
        Rectangle answer1Rect = { 150, 205, 500, 50 }; // Adjust width as needed
        Rectangle answer2Rect = { 150, 275, 500, 50 };
        Rectangle answer3Rect = { 150, 345, 500, 50 };

        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, answer1Rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            usersAnswers[currentQuestion] = 1;
            questions[currentQuestion].chosenAnswer = questions[currentQuestion].answer1;
        }

        if (CheckCollisionPointRec(mousePosition, answer2Rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            usersAnswers[currentQuestion] = 2;
            questions[currentQuestion].chosenAnswer = questions[currentQuestion].answer2;
        }

        if (CheckCollisionPointRec(mousePosition, answer3Rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            usersAnswers[currentQuestion] = 3;
            questions[currentQuestion].chosenAnswer = questions[currentQuestion].answer3;
        }
    }
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);

    if (currentState == START_SCREEN) {
        DrawTexture(startButtonImage, 260, 185, WHITE);
    }

    if (currentState == PLAYING) {
        // Draw question
        DrawText(questions[currentQuestion].question.c_str(), 150, 135, 20, BLACK);

        // Draw answer texts with potential hover or selection effects
        Color answer1Color = (CheckCollisionPointRec(GetMousePosition(), { 150, 205, 500, 50 })) ? LIGHTGRAY : BLACK;
        Color answer2Color = (CheckCollisionPointRec(GetMousePosition(), { 150, 275, 500, 50 })) ? LIGHTGRAY : BLACK;
        Color answer3Color = (CheckCollisionPointRec(GetMousePosition(), { 150, 345, 500, 50 })) ? LIGHTGRAY : BLACK;

        DrawText(questions[currentQuestion].answer1.c_str(), 150, 205, 20, answer1Color);
        DrawText(questions[currentQuestion].answer2.c_str(), 150, 275, 20, answer2Color);
        DrawText(questions[currentQuestion].answer3.c_str(), 150, 345, 20, answer3Color);

        // Optional: Draw rectangles around text for visual debugging
        // DrawRectangleLines(150, 205, 500, 50, GRAY);
        // DrawRectangleLines(150, 275, 500, 50, GRAY);
        // DrawRectangleLines(150, 345, 500, 50, GRAY);
    }
}

