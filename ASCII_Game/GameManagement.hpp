#include <algorithm>
#include <chrono>
#include <windows.h>
#include "WindowHandler.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Cannon.hpp"
#include "Dollar.hpp"
#include "Percent.hpp"
#include "At.hpp"
#include "ShootableObjectFactory.hpp"
#include "MovableObjectFactory.hpp"
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

	void addCannonToShootableObjVector(int _xPos, int _yPos, int _timeDelay, bool _isVer, char _shootDir);
	void addPercentToMoveableObjVector(int _xPos, int _yPos, int _xStart, int _xEnd, int _yStart, int _yEnd);
	void addDollarToMoveableObjVector(int _xPos, int _yPos, char _moveDir);

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

	void clearCell(int xPos, int yPos);
	void drawBoard();

	// Player
	void movePlayer();
	void putPlayer();
	void drawPlayer();
	void killPlayer();

	CollisionState checkIfCollision(int newXPos, int newYPos, char currType);
	bool checkIfCheckpoint(int newXPos, int newYPos);

	//Cannons
	void initBullet(ShootableObject* cannon, int xMove, int yMove);
	void shootCannon(long long mcr);
	void moveBullet(ShootableObject* cannon, int xMove, int yMove);
	void drawBullet(int xPos, int yPos);

	//Dollars
	void moveObjects();

	//Ats
	void putAt(Object* at);
	void drawAt(Object* at);
	vector<Object*>::iterator findAt(int xPos, int yPos);
	bool moveAt(Object* at, int xDir, int yDir);

	const vector<Object*>& getAts() const;

	Board* getBoard() const;
	vector<ShootableObject*> getCannons() const;
	Player* getPlayer() const;
};
 
