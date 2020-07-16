#include "WindowHandler.h"

constexpr auto DARK_RED = 4;
constexpr auto RED = 12;
constexpr auto LIGHT_BLUE = 11;
constexpr auto WHITE = 15;

void WindowHandler::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void WindowHandler::changeColor(int nameNumber)
{
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
