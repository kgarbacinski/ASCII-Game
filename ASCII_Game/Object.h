#include <windows.h>
#include "WindowHandler.h"
#pragma once
class Object : public WindowHandler
{
protected:
	int xPos;
	int yPos;
	bool isVer;
	char reprVer;
	char reprHor;
public:
	Object(int _xPos, int _yPos, char _reprVer, char _reprHor, bool _isVer) : xPos{ _xPos }, yPos{ _yPos }, reprHor{ _reprHor }, reprVer{ _reprVer }, isVer{ _isVer } {
	}

	virtual void drawBullet(int xPos, int yPos) = 0;

	char getReprVer() { return this->reprVer; }
	char getReprHor() { return this->reprHor; }
	bool getIsVer() { return this->isVer; }
	int getXPos() { return this->xPos; }
	int getYPos() { return this->yPos; }
};

