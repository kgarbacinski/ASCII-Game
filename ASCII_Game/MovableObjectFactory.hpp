#include "MovableObject.hpp"
#include "Percent.hpp"
#include "Dollar.hpp"

#pragma once
class MovableObjectFactory
{
public:
	MovableObjectFactory() = default;
	~MovableObjectFactory() = default;
	
	MovableObject* createPercent(int _xPos, int _yPos, int _xStart, int _xEnd, int _yStart, int _yEnd);
	MovableObject* createDollar(int _xPos, int _yPos, char _moveDir);
};

