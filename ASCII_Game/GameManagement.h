#include <windows.h>
#include "WindowHandler.h"
#include "Board.h"
#include "Player.h"
#include "Cannon.h"


#pragma once
class GameManagement : public WindowHandler
{
private:
	//Create objects
	vector<Cannon*> cannons{ 
		new Cannon(5, 25, 1000, true, 'D'), // first from left, section down
		new Cannon(5,15,1000,true,'D'),
		new Cannon(11,28,1000,false,'R')
	
	};

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

	// Basic methods
	void drawObjects();
	void putObjects();
	void drawPlayer();
	void clearCell(int xPos, int yPos);
	void drawBoard();
	void movePlayer();

	int checkIfCollision(int newXPos, int newYPos);

	//Cannons
	void initBullet(Cannon* cannon, int xMove, int yMove);
	void shootCannonSlow();
	void shootCannonFast();
	void moveBullet(Cannon* cannon, int xMove, int yMove);
	void drawBullet(int xPos, int yPos);

	Board* getBoard() const;
	vector<Cannon*> getCannons() const;
	Player* getPlayer() const;
};

