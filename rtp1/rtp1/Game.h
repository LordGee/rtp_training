#pragma once

class Game {
private:
	int m_Score;
	int m_Lives;

public:
	enum GameType {
		PONG,
		PACMAN,
		SPACEINVADERS
	};
public:
	Game ();
	Game(GameType _type);
	~Game ();

private:

};