#include "GameManagement.h"

GameManagement* GameManagement::instance = nullptr;

GameManagement::GameManagement() {}

void GameManagement::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GameManagement::drawPlayer()
{
	this->gotoxy(this->getPlayer()->getxPos(), this->getPlayer()->getyPos()); // place console cursor on certain pos
	cout << "I";
}

void GameManagement::clearPlayer(int xPos, int yPos)
{
	gotoxy(xPos, yPos);
	cout << ' ';
}

void GameManagement::drawBoard() {
	gotoxy(0, 0);

	for (auto line : this->getBoard()->getBoardASCII()) {
		cout << line << endl;
	}
}

void GameManagement::movePlayer()
{
	int xPos = this->player->getxPos(), yPos = this->player->getyPos();

	if (GetKeyState('A') < 0) {
		if (this->checkIfCollision(xPos - 1, yPos) != 0) { // player on the wall
			this->player->setxPos(xPos - 1);
			this->clearPlayer(xPos, yPos);
			this->drawPlayer();

			Sleep(200);
		}
		
	}
	
	else if (GetKeyState('D') & 0x8000) {
		if (this->checkIfCollision(xPos + 1, yPos) != 0) {
			this->player->setxPos(xPos + 1);
			this->clearPlayer(xPos, yPos);
			this->drawPlayer();
			Sleep(200);
		}
		
	}
	else if (GetKeyState('W') & 0x8000) {
		if (this->checkIfCollision(xPos, yPos - 1) != 0) {
			this->player->setyPos(yPos - 1);
			this->clearPlayer(xPos, yPos);
			this->drawPlayer();
			Sleep(200);
		}
	}
	else if (GetKeyState('S') & 0x8000) {
		if (this->checkIfCollision(xPos, yPos + 1) != 0) {
			this->player->setyPos(yPos + 1);
			this->clearPlayer(xPos, yPos);
			this->drawPlayer();
			Sleep(200);
		}
	}
	
}

int GameManagement::checkIfCollision(int newXPos, int newYPos)
{
	// Check wall
	if (this->board->getBoardASCII().at(newYPos).at(newXPos) == '#') {
		return 0; // dla sciany
	}

	return -1;
}

Board* GameManagement::getBoard() const
{
	return this->board;
}

Player* GameManagement::getPlayer() const
{
	return this->player;
}
