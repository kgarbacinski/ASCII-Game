#include <algorithm>
#include <chrono>
#include <windows.h>
#include "WindowHandler.h"
#include "Board.h"
#include "Player.h"
#include "Cannon.h"
#include "Dollar.h"
#include "At.h"
#include "MovableObject.h"
#include "ShootableObject.h"

using std::find_if;
using namespace std::chrono;

enum timeDelay {
	CANNON_FAST = 500000,
	CANNON_SLOW = 1000000,
	DOLLAR_NORMAL = 500000
};

enum class CollisionState {
	EMPTY_FIELD,
	AT,
	DEATH,
	WALL
};

#pragma once
class GameManagement : public WindowHandler
{
private:
	//Create objects
	vector<ShootableObject*> shootableObjects{
		new Cannon(5, 25, timeDelay::CANNON_SLOW, true, 'D'), // first from left, section down

		new Cannon(5,15, timeDelay::CANNON_SLOW,true,'D'),

		new Cannon(11, 28, timeDelay::CANNON_SLOW, false, 'R'),

		// One row
		new Cannon(26, 29, timeDelay::CANNON_FAST, true, 'D'),
		new Cannon(27, 29, timeDelay::CANNON_SLOW, true, 'D'),
		new Cannon(28, 29, timeDelay::CANNON_FAST, true, 'D'),
		new Cannon(29, 29, timeDelay::CANNON_SLOW, true, 'D'),

		new Cannon(31, 29, timeDelay::CANNON_FAST, true, 'D'),
		new Cannon(32, 29, timeDelay::CANNON_SLOW, true, 'D'),
		new Cannon(33, 29, timeDelay::CANNON_FAST, true, 'D'),
		new Cannon(34, 29, timeDelay::CANNON_SLOW, true, 'D'),
		new Cannon(35, 29, timeDelay::CANNON_FAST, true, 'D'),
		new Cannon(36, 29, timeDelay::CANNON_SLOW, true, 'D'),

		new Cannon(41,36, timeDelay::CANNON_SLOW,true,'U'),
		new Cannon(43,36, timeDelay::CANNON_FAST,true,'U'),
		new Cannon(45,36, timeDelay::CANNON_FAST,true,'U'),
		new Cannon(47,36, timeDelay::CANNON_SLOW,true,'U')
	};

	vector<MovableObject*> movableObjects{
		new Dollar(10, 31, 'L'),
		new Dollar(10, 33 ,'R')
	};

	vector<Object*> ats{
		new At(56, 26),
		new At(57, 34)
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
	void drawShotObjects();
	void putShotObjects();
	void putMovObjects();
	void drawMovObjects();
	void clearCell(const int& xPos, const int& yPos);
	void drawBoard();

	// Player
	void movePlayer();
	void putPlayer();
	void drawPlayer();
	void killPlayer();

	CollisionState checkIfCollision(const int& newXPos, const int& newYPos);

	//Cannons
	void initBullet(ShootableObject* cannon, const int& xMove, const int& yMove);
	void shootCannon(long long mcr);
	void moveBullet(ShootableObject* cannon, const int& xMove,const int& yMove);
	void drawBullet(const int& xPos, const int& yPos);

	//Dollars
	void moveDollars();

	//Ats
	void putAt(Object* at);
	void drawAt(Object* at);
	vector<Object*>::iterator findAt(const int& xPos, const int& yPos);
	bool moveAt(Object* at, const int& xDir, const int& yDir);

	const vector<Object*>& getAts() const;

	Board* getBoard() const;
	vector<ShootableObject*> getCannons() const;
	Player* getPlayer() const;
};
 
