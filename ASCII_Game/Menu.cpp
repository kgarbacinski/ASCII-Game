#include "Menu.h"

Menu* Menu::instance = nullptr;

Menu::Menu() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	this->windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	this->windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	this->cursorXPos = this->windowWidth / 2 - 5;
	this->cursorYPos = this->windowHeight / 2;
}

Menu::~Menu()
{
	delete instance;
}

Menu* Menu::getInstance()
{
	if (instance == nullptr) {
		instance = new Menu();
	}
	return instance;
}

void Menu::drawMenu()
{
	this->drawCursor();
	this->gotoxy(windowWidth / 2, windowHeight / 2);
	std::cout << "START";
	this->gotoxy(windowWidth / 2, windowHeight / 2 + 1);
	std::cout << "EXIT";

	this->waitForInput();
}

void Menu::waitForInput()
{
	while (true) {
		switch (_getch()) {
			case 115:
				this->moveCursor(0, 1);
				break;
		}
	}
}

void Menu::drawCursor()
{
	this->gotoxy(this->cursorXPos, this->cursorYPos);
	std::cout << ">";
}

void Menu::clearCursor()
{
	this->gotoxy(this->cursorXPos, this->cursorYPos);
	std::cout << " ";
}

void Menu::moveCursor(int xMove, int yMove)
{
	if (this->cursorYPos + yMove < this->windowHeight / 2 + noOptions) {
		this->clearCursor();
		this->cursorYPos += yMove;
		this->drawCursor();
	}

}
