#pragma once
#include "pch.h"
#include "gameState.h"

struct QuestionsModel {
	string question;
	string answer1;
	string answer2;
	string answer3;
	string correct;
	string chosenAnswer;

};


class Questions {
public:
	vector <QuestionsModel> getQuestions();
};