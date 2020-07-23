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
	WHITE = 15
};

#pragma once
class WindowHandler
{
private:
	std::mutex mtx;
protected:
	void moveCursor(int x, int y, Colours colour=Colours::NONE, char symbol=' ');
	void changeColor(int nameNumber);
};

