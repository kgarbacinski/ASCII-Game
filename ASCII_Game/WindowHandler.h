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
	LIGHT_GREEN = 10,
	GRAY = 7
};

#pragma once
class WindowHandler
{
private:
	std::mutex mtx;
protected:
	void gotoxy(const int& x, const int& y);
	void changeColor(const int& nameNumber);
};

