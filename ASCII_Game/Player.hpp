#pragma once
#include "Object.hpp"

class Player : public Object
{
private:
	const int startxPos{ 2 }; // 2
	const int startyPos{ 36 }; // 36

	int timeDelay;
	int xCheckpoint, yCheckpoint;
	int health;
public:
	Player(int _timeDelay = 100000, int _xCheckpoint = 2, int _yCheckpoint = 36, int _xPos = 2, int _yPos = 36, int _health = 100);

	int getStartxPos() const;
	int getStartyPos() const;
	int getTimeDelay() const;
	int getxPos() const;
	int getyPos() const;
	int getHealth() const;
	int getXCheckpoint() const;
	int getYCheckpoint() const;

	void setCheckpoint(int xPos, int yPos);
	void setxPos(int _xPos);
	void setyPos(int _yPos);
	void setHealth(int _health);

};

