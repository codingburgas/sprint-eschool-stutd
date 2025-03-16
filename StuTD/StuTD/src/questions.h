#pragma once
#include "pch.h"
class questions {
public:
	questions();
	void Draw();
	void Update();
	vector<vector<string>> questionsText;
	vector<int> correctAnswers;

	Texture2D background;
	Texture2D startButtonImage;

	void LoadStartButtonImage();
 private:
	 int currentQuestion;
};