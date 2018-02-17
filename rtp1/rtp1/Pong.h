#pragma once
#include "Game.h"

class Pong : public Game
{
private:
	int minWidthHeight = 5, maxWidth = 500, maxHeight = 500;

public:
	Pong();
	~Pong();

private:
	void DrawGrid();
};