#include <windows.h>

#include "Board.h"
#include "Player.h"

#pragma once
class GameManagement
{
private:
	// Create board
	Board* board{new Board()};
	//Create player
	Player* player{new Player()};

	static GameManagement* instance;
	GameManagement();
public:
	static GameManagement* getInstance() {
		if (instance == nullptr) {
			instance = new GameManagement();
		}

		return instance;
	}

	void gotoxy(int x, int y);
	void drawPlayer();
	void clearPlayer(int xPos, int yPos);
	void drawBoard();
	void movePlayer();

	int checkIfCollision(int newXPos, int newYPos);

	Board* getBoard() const;
	Player* getPlayer() const;
};

