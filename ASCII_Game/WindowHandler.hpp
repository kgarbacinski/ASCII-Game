#include <windows.h>
#include <string>
#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>

enum Colours {
	NONE = 0,
	DARK_RED = 4,
	RED = 12,
	LIGHT_BLUE = 11,
	WHITE = 15,
	LIGHT_GREEN = 10,
	GRAY = 7,
	PURPLE = 13
};

#pragma once
class WindowHandler
{
protected:
	void gotoxy(int x, int y);
	void changeColor(int nameNumber);

	virtual ~WindowHandler() {}
};

