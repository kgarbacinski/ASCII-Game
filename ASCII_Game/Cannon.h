#include <iostream>
#include "Object.h"
#include "WindowHandler.h"

using std::cout;

#pragma once
class Cannon : public Object
{
private:
	char reprBullet{ 'o' };
	char shootDir; // 'L', 'R', | 'U', 'D'

public:
	Cannon(const int& _xPos, const int& _yPos, const int& _timeDelay,const bool& _isVer, const char& _shootDir);
	
	void drawBullet(const int& xPos, const int& yPos);

	char getReprBullet();
	char getShootDir();
};

