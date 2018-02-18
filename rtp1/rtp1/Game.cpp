#include "Game.h"
#include "frm_main.h"
#include <fstream>

rtp1::Game::Game() { }

rtp1::Game::Game(GameType _type)
{
	m_GameRunning = true;
	m_BackgroundGrid = new std::vector<Grid>;
	if (_type == PONG) {
		LoadGrid(PONG_FILE);
	}
	GameLoop();
}

rtp1::Game::~Game()
{
	
}

void rtp1::Game::GameLoop()
{
	
}

void rtp1::Game::LoadGrid(const char* _filename)
{
	std::ifstream readGrid;
	readGrid.open(_filename);
	int x = 0, y = 0, c = 0;
	char output;
	if (readGrid.is_open()) {
		while (!readGrid.eof()) {
			readGrid >> std::noskipws >> output;
			if (output == ' ') {
				x++;
			} else {
				if (output != '\n') {
					Grid g;
					g.object = output;
					g.posX = x;
					g.posY = y;
					m_BackgroundGrid->push_back(g);
					x++;
				} else {
					x = 0;
					y++;
				}
			}
		}
	}
	readGrid.close();
}
