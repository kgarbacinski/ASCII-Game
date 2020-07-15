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

void GameManagement::drawObjects()
{
	for (auto cannon : this->cannons) {
		cannon->drawObject();
	}
}

void GameManagement::putObjects() {
	for (auto cannon : this->cannons) {
		board->modifyBoardASCII(cannon->getXPos(), cannon->getYPos(), 'c');
	}
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
	while (true) {
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
	
}

int GameManagement::checkIfCollision(int newXPos, int newYPos)
{
	// Check wall
	if (this->board->getBoardASCII().at(newYPos).at(newXPos) == '#' || 
		this->board->getBoardASCII().at(newYPos).at(newXPos) == 'c') {
		return 0; // dla sciany
	}

	return -1; // puste pole
}

void GameManagement::moveBullet()
{
	for (int i = 0; i < this->board->getBoardASCII().size(); i++) {
		string line = this->board->getBoardASCII().at(i);
		for (int j = 0; j < line.size(); j++) {
			if (line.at(j) == 'H' && checkIfCollision(i - 1, j) == -1) {
				this->board->modifyBoardASCII(i - 1, j, 'H');
			}
			this->board->modifyBoardASCII(i, j, ' ');
		}
	}
}

void GameManagement::drawBullets() {
	for (int i = 0; i < this->board->getBoardASCII().size(); i++) {
		string line = this->board->getBoardASCII().at(i);
		for (int j = 0; j < line.size(); j++) {
			if (line.at(j) == 'H') {
				this->gotoxy(i, j);
				cout << this->cannons.at(0)->getReprBullet();
			}
		}
	}
}

void GameManagement::shootCannonSlow() {
	while (true) {
		for (auto cannon : this->cannons) {
			this->moveBullet();
			this->drawBullets();
		}
		Sleep(1000);
	}
	
}

void GameManagement::shootCannonFast() {
	Sleep(200);
}

Board* GameManagement::getBoard() const
{
	return this->board;
}

Player* GameManagement::getPlayer() const
{
	return this->player;
}
