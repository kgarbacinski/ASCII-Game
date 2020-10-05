#include "MovableObject.hpp"

#pragma once
class Percent : public MovableObject
{
private:
	int xStart;
	int xEnd;
	int yStart;
	int yEnd;
public:
	Percent(int _xPos, int _yPos, int _xStart, int _xEnd, int _yStart, int _yEnd);
	~Percent();
	void moveObject() override;
};

