#include "Object.h"

#pragma once
class Dollar : public Object
{
private:
	int xDir; // -1, 1
public:
	Dollar(const int& _xPos, const int& _yPos, const int& _xDir, const char& _repr);

	const int& getXDir() const ;
	void setXDir(const int& _xDir);
};

