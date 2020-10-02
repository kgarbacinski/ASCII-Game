#include "ShootableObjectFactory.hpp"

ShootableObject* ShootableObjectFactory::createCannon(int _xPos, int _yPos, int _timeDelay, bool _isVer, char _shootDir)
{
	return new Cannon(_xPos, _yPos, _timeDelay, _isVer, _shootDir);
}
