#include <windows.h>
#include "WindowHandler.h"
#pragma once
class Object : public WindowHandler
{
protected:
	int xPos;
	int yPos;
	char reprVer;
	char reprHor;
public:
	Object(int _xPos, int _yPos, char _reprVer, char _reprHor) : xPos{ _xPos }, yPos{ _yPos }, reprHor{ _reprHor }, reprVer{_reprVer} {
	}

	virtual void drawObject() = 0;

	int getXPos() { return this->xPos; }
	int getYPos() { return this->yPos; }
};

