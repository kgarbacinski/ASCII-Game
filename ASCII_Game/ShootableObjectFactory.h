#include "ShootableObject.h"
#include "Cannon.h"

#pragma once
class ShootableObjectFactory
{
public:
	ShootableObject* createCannon(const int& _xPos, const int& _yPos, const int& _timeDelay, const bool& _isVer, const char& _shootDir);
};

