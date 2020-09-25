#include <windows.h>
#include <iostream>

#include "WindowHandler.h"

using std::cout;
#pragma once
class Object : public WindowHandler
{
protected:
	int xPos;
	int yPos;
	char repr;

public:
	Object(int _xPos, int _yPos, char _reprVer, char _reprHor, bool _isVer) : xPos { _xPos }, yPos{ _yPos } {
		if (_isVer) this->repr = _reprVer;
		else this->repr = _reprHor;		
	}
	virtual ~Object() {}

	void drawObject() {
		cout << this->repr;
	}

	const char& getRepr() const { return this->repr; }
	const int& getXPos() const { return this->xPos; }
	const int& getYPos() const { return this->yPos; }

	void setXPos(const int& _xPos) { this->xPos = _xPos; }
	void setYPos(const int& _yPos) { this->yPos = _yPos; }
};

