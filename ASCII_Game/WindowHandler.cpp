#include "WindowHandler.hpp"

void WindowHandler::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
		case LIGHT_GREEN:
			SetConsoleTextAttribute(hConsole, LIGHT_GREEN);
			break;
		case GRAY:
			SetConsoleTextAttribute(hConsole, GRAY);
			break;
		case PURPLE:
			SetConsoleTextAttribute(hConsole, PURPLE);
			break;
	}
}
