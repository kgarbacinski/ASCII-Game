#include "ShootableObjectFactory.h"

ShootableObject* ShootableObjectFactory::createCannon(const int& _xPos, const int& _yPos, const int& _timeDelay, const bool& _isVer, const char& _shootDir)
{
	return new Cannon(_xPos, _yPos, _timeDelay, _isVer, _shootDir);
}
