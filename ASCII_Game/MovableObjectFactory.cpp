#include "MovableObjectFactory.h"

MovableObject* MovableObjectFactory::createPercent(const int& _xPos, const int& _yPos, const int& _xStart, const int& _xEnd, const int& _yStart, const int& _yEnd)
{
	return new Percent(_xPos, _yPos, _xStart, _xEnd, _yStart, _yEnd);
}

MovableObject* MovableObjectFactory::createDollar(const int& _xPos, const int& _yPos, const char& _moveDir)
{
	return new Dollar(_xPos, _yPos, _moveDir);
}
