#include <windows.h>

#pragma once
class Object
{
protected:
	int xPos;
	int yPos;
	char reprVer;
	char reprHor;
public:
	Object(int _xPos, int _yPos, char _reprVer, char _reprHor) : xPos{ _xPos }, yPos{ _yPos }, reprHor{ _reprHor }, reprVer{_reprVer} {
	}

	virtual void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	virtual void drawObject() = 0;

	int getXPos() { return this->xPos; }
	int getYPos() { return this->yPos; }
};

