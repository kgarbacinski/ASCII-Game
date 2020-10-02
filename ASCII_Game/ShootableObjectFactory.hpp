#include "ShootableObject.hpp"
#include "Cannon.hpp"

#pragma once
class ShootableObjectFactory
{
public:
	ShootableObject* createCannon(int _xPos, int _yPos, int _timeDelay, bool _isVer, char _shootDir);
};

