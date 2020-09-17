#include <algorithm>
#include <chrono>
#include <windows.h>
#include "WindowHandler.h"
#include "Board.h"
#include "Player.h"
#include "Cannon.h"
#include "Dollar.h"
#include "Percent.h"
#include "At.h"
#include "ShootableObjectFactory.h"
#include "MovableObjectFactory.h"
#include <memory>
#include <stack>

using std::make_pair;
using std::stack;
using std::pair;
using std::unique_ptr;
using std::find_if;
using namespace std::chrono;

enum timeDelay {
	CANNON_FAST = 500000,
	CANNON_SLOW = 1000000,
	MOVABLE_OBJECT = 250000
};


#pragma once
class GameManagement : public WindowHandler
{
private:
	ShootableObjectFactory* shootableObjectFactory{ new ShootableObjectFactory() };
	MovableObjectFactory* movableObjectFactory{ new MovableObjectFactory() };
	
	vector<ShootableObject*> shootableObjects;
	vector<MovableObject*> movableObjects;

	void addCannonToShootableObjVector(const int& _xPos, const int& _yPos, const int& _timeDelay, const bool& _isVer, const char& _shootDir);
	void addPercentToMoveableObjVector(const int& _xPos, const int& _yPos, const int& _xStart, const int& _xEnd, const int& _yStart, const int& _yEnd);
	void addDollarToMoveableObjVector(const int& _xPos, const int& _yPos, const char& _moveDir);

	vector<Object*> ats;

	// Create board
	Board* board{new Board()};
	//Create player
	Player* player{new Player()};

	//Checkpoints
	stack<pair<int, int>> checkpointsStack;

	static GameManagement* instance;
	GameManagement();
	~GameManagement();

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
	void drawCheckpoints();

	void clearCell(const int& xPos, const int& yPos);
	void drawBoard();

	// Player
	void movePlayer();
	void putPlayer();
	void drawPlayer();
	void killPlayer();

	CollisionState checkIfCollision(const int& newXPos, const int& newYPos, char currType);
	bool checkIfCheckpoint(const int& newXPos, const int& newYPos);

	//Cannons
	void initBullet(ShootableObject* cannon, const int& xMove, const int& yMove);
	void shootCannon(long long mcr);
	void moveBullet(ShootableObject* cannon, const int& xMove,const int& yMove);
	void drawBullet(const int& xPos, const int& yPos);

	//Dollars
	void moveObjects();

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
 
