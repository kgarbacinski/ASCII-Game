#include <windows.h>
#include "WindowHandler.h"
#pragma once
class Object : public WindowHandler
{
protected:
	int timeDelay;

	int xPos;
	int yPos;
	bool isVer;
	char reprVer;
	char reprHor;
public:
	Object(int _xPos, int _yPos, char _reprVer, char _reprHor, int _timeDelay = 0, bool _isVer = true) : xPos{ _xPos }, yPos{ _yPos }, reprHor{ _reprHor }, reprVer{ _reprVer }, timeDelay{_timeDelay}, isVer{ _isVer } {
	}

	const int& getTimeDelay() const { return this->timeDelay; }
	const char& getReprVer() const { return this->reprVer; }
	const char& getReprHor() const { return this->reprHor; }
	const bool& getIsVer() const { return this->isVer; }
	const int& getXPos() const { return this->xPos; }
	const int& getYPos() const { return this->yPos; }
	void setXPos(const int& _xPos);
	void setYPos(const int& _yPos);
};

