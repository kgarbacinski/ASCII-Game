#include <windows.h>
#include <iostream>

#include "WindowHandler.hpp"

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

	void setRepr(char repr_) { this->repr = repr_; }
	char getRepr() const { return this->repr; }
	int getXPos() const { return this->xPos; }
	int getYPos() const { return this->yPos; }

	void setXPos(int _xPos) { this->xPos = _xPos; }
	void setYPos(int _yPos) { this->yPos = _yPos; }
};

