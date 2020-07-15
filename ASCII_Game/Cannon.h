#include <iostream>
#include "Object.h"

using std::cout;

#pragma once
class Cannon : public Object
{
private:
	int shootDelay; // in ms
	char reprBullet{ 'o' };
	bool isVer;

public:
	Cannon(int _xPos, int _yPos, int _shootDelay, bool _isVer);
	
	void drawObject();
	void drawBullet(int xPos, int yPos);

	char getReprBullet();
};

