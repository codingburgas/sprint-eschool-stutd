#pragma once
#include "pch.h"

enum GameState {
	START_SCREEN,
	PLAYING,
	GAME_OVER
};

GameState currentState = START_SCREEN;