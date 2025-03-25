#include "pch.h"
#include "questions.h"
#include "gameState.h"
#include "game.h"


vector<QuestionsModel> Questions::getQuestions()
{
    vector<QuestionsModel> questions;
    ifstream file("../files/questions.txt");
    if (!file) {
        cout << "Unable to open the file";
    }
    string line;
    while (getline(file, line))
    {
        QuestionsModel question;
        question.question = line;
        getline(file, line);
        question.answer1 = line;
        getline(file, line);
        question.answer2 = line;
        getline(file, line);
        question.answer3 = line;
        getline(file, line);
        question.correct = line;
        questions.push_back(question);
    }
    file.close();
    random_device rd;
    uniform_int_distribution<int> random(0, 49);
    int score = 0;
    vector<QuestionsModel> selectedQuestions;
    for (int i = 0; i < 15; i++)
    {
        int index = random(rd);
        selectedQuestions.push_back(questions[index]);
    }
    return selectedQuestions;
}