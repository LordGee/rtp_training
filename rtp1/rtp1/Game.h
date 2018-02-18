#pragma once

#include "Grid.h"
#include <vector>

namespace rtp1 {

	class Game {
	private:
		bool m_GameRunning;
		int m_Score;
		int m_Lives;

	public:
		std::vector<Grid> *m_BackgroundGrid;

	private:
		const char* PONG_FILE = "res/pong_half_grid.csv";

	public:
		enum GameType {
			PONG,
			PACMAN,
			SPACEINVADERS
		};

	public:
		Game();
		Game(GameType _type);
		~Game();

	private:
		void GameLoop();
		void LoadGrid(const char* filename);
	};

}