#include <iostream>
#include "ShootableObject.hpp"
#include "WindowHandler.hpp"

using std::cout;

#pragma once
class Cannon : public ShootableObject
{
public:
	Cannon(int _xPos, int _yPos, int _timeDelay, bool _isVer, char _shootDir);
	~Cannon();
};

