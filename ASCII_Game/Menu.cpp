#include "Menu.hpp"

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
	while (isMenuRunning) {
		switch (_getch()) {
			case 115:
				this->moveCursor(0, 1);
				break;
			case 119:
				this->moveCursor(0,-1);
				break;
			case 13:
				this->checkConfirmation();
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
	if (this->cursorYPos + yMove < this->windowHeight / 2 + noOptions && 
		this->cursorYPos + yMove > this->windowHeight / 2 - 1) {
		this->clearCursor();
		this->cursorYPos += yMove;
		this->drawCursor();

		this->currOption += yMove;
	}

}

void Menu::checkConfirmation()
{
	switch (this->currOption) {
		case 0: // START
			this->isMenuRunning = false;
			break;
		case 1: // EXIT
			this->isMenuRunning = false;
			system("cls");
			exit(0);
			break;
	}
}
