#include "Object.h"

#pragma once
class Dollar : public Object
{
private:
	int xDir; // -1, 1
public:
	Dollar(int _xPos, int _yPos, int _xDir, char _repr);

	int getXDir();
	void setXDir(int _xDir);
};

