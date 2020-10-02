#include "MovableObjectFactory.hpp"

MovableObject* MovableObjectFactory::createPercent(int _xPos, int _yPos, int _xStart, int _xEnd, int _yStart, int _yEnd)
{
	return new Percent(_xPos, _yPos, _xStart, _xEnd, _yStart, _yEnd);
}

MovableObject* MovableObjectFactory::createDollar(int _xPos, int _yPos, char _moveDir)
{
	return new Dollar(_xPos, _yPos, _moveDir);
}
