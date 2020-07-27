#include <algorithm>
#include <chrono>
#include <windows.h>
#include "WindowHandler.h"
#include "Board.h"
#include "Player.h"
#include "Cannon.h"
#include "Dollar.h"
#include "At.h"

using std::find_if;
using namespace std::chrono;
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

	vector<Dollar*> dollars{
		new Dollar(10, 31, -1, '$'),
		new Dollar(10, 33 ,1, '$')
	};

	vector<At*> ats{
		new At(56, 26, '@'),
		new At(57, 34, '@')
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
	void putDollars();
	void drawDollars();
	void clearCell(const int& xPos, const int& yPos);
	void drawBoard();

	// Player
	void movePlayer();
	void putPlayer();
	void drawPlayer();
	void killPlayer();

	int checkIfCollision(const int& newXPos, const int& newYPos);

	//Cannons
	void initBullet(Cannon* cannon, const int& xMove, const int& yMove);
	void shootCannonSlow();
	void shootCannonFast();
	void moveBullet(Cannon* cannon, const int& xMove,const int& yMove);
	void drawBullet(const int& xPos, const int& yPos);

	//Dollars
	void moveDollars();

	//Ats
	void putAt(At* at);
	void drawAt(At* at);
	vector<At*>::iterator findAt(const int& xPos, const int& yPos);
	bool moveAt(At* at, const int& xDir, const int& yDir);

	const vector<At*>& getAts() const;

	Board* getBoard() const;
	vector<Cannon*> getCannons() const;
	Player* getPlayer() const;
};
 
