#include <windows.h>
#include <string>
#include <thread>
#include <mutex>
#include <iostream>

enum Colours {
	NONE = 0,
	DARK_RED = 4,
	RED = 12,
	LIGHT_BLUE = 11,
	WHITE = 15,
	LIGHT_GREEN = 10
};

#pragma once
class WindowHandler
{
private:
	std::mutex mtx;
protected:
	void gotoxy(int x, int y);
	void changeColor(int nameNumber);
};

