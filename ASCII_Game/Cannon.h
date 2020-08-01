#include <iostream>
#include "ShootableObject.h"
#include "WindowHandler.h"

using std::cout;

#pragma once
class Cannon : public ShootableObject
{
public:
	Cannon(const int& _xPos, const int& _yPos, const int& _timeDelay,const bool& _isVer, const char& _shootDir);
};

