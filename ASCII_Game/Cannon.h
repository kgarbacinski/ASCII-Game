#include <iostream>
#include "Object.h"

using std::cout;

#pragma once
class Cannon : public Object
{
private:
	int shootDelay; // in ms

public:
	Cannon(int _xPos, int _yPos, int _shootDelay);
	void drawObject(bool isVer = true);
};

