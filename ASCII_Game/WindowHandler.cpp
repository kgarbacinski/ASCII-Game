#include "WindowHandler.h"

void WindowHandler::moveCursor(int x, int y, Colours colour, char symbol)
{
	mtx.lock();
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	if (colour != Colours::NONE)
		this->changeColor(colour);
	if(symbol != ' ')
		std::cout << symbol;
	mtx.unlock();
}

void WindowHandler::changeColor(int nameNumber){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (nameNumber) {
		case RED:
			SetConsoleTextAttribute(hConsole, RED);
			break;
		case DARK_RED:
			SetConsoleTextAttribute(hConsole, DARK_RED);
			break;
		case LIGHT_BLUE:
			SetConsoleTextAttribute(hConsole, LIGHT_BLUE);
			break;
		case WHITE:
			SetConsoleTextAttribute(hConsole, WHITE);
			break;
	}
}
