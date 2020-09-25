#include "MovableObject.h"
#include "Percent.h"
#include "Dollar.h"

#pragma once
class MovableObjectFactory
{
public:
	MovableObjectFactory() = default;
	~MovableObjectFactory() = default;
	MovableObject* createPercent(const int& _xPos, const int& _yPos, const int& _xStart, const int& _xEnd, const int& _yStart, const int& _yEnd);
	MovableObject* createDollar(const int& _xPos, const int& _yPos, const char& _moveDir);
};

