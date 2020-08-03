#include "MovableObject.h"

#pragma once
class Percent : public MovableObject
{
private:
	int xStart;
	int xEnd;
	int yStart;
	int yEnd;
public:
	Percent(const int& _xPos, const int& _yPos, const int& _xStart, const int& _xEnd, const int& _yStart, const int& _yEnd);
	void moveObject() override;
};

