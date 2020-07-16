#include <iostream>
#include "Object.h"
#include "WindowHandler.h"

using std::cout;

#pragma once
class Cannon : public Object
{
private:
	int shootDelay; // in ms
	char reprBullet{ 'o' };
	bool isVer;
	char shootDir; // 'L', 'R', | 'U', 'D'

public:
	Cannon(int _xPos, int _yPos, int _shootDelay, bool _isVer, char _shootDir);
	
	void drawObject();
	void drawBullet(int xPos, int yPos);

	int getShootDelay();
	char getReprBullet();
	bool getIsVer();
	char getShootDir();
};

