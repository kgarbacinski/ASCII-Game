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

		new Cannon(11, 28, 1000, false, 'R'),

		// One row
		new Cannon(26, 29, 400, true, 'D'),
		new Cannon(27, 29, 1000, true, 'D'),
		new Cannon(28, 29, 400, true, 'D'),
		new Cannon(29, 29, 400, true, 'D'),

		new Cannon(31, 29, 1000, true, 'D'),
		new Cannon(32, 29, 1000, true, 'D'),
		new Cannon(33, 29, 400, true, 'D'),
		new Cannon(34, 29, 1000, true, 'D'),
		new Cannon(35, 29, 400, true, 'D'),
		new Cannon(36, 29, 1000, true, 'D'),

		new Cannon(41,36,1000,true,'U'),
		new Cannon(42,36,1000,true,'U'),
		new Cannon(43,36,1000,true,'U'),
		new Cannon(44,36,1000,true,'U'),
		new Cannon(45,36,1000,true,'U'),
		new Cannon(46,36,1000,true,'U'),
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
	void drawCannons();
	void putCannons();
	void clearCell(int xPos, int yPos);
	void drawBoard();

	// Player
	void movePlayer();
	void putPlayer();
	void killPlayer();

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
 
