#include "GameManagement.h"

constexpr auto DARK_RED = 4;
constexpr auto RED = 12;
constexpr auto LIGHT_BLUE = 11;
constexpr auto WHITE = 15;

GameManagement* GameManagement::instance = nullptr;

GameManagement::GameManagement() {}


void GameManagement::drawObjects()
{
	for (auto cannon : this->cannons) {
		this->changeColor(DARK_RED);
		cannon->drawObject();
		this->changeColor(WHITE);
	}
}

void GameManagement::putObjects() {
	for (auto cannon : this->cannons) {
		board->modifyBoardASCII(cannon->getXPos(), cannon->getYPos(), 'c');
	}
}

void GameManagement::drawPlayer()
{
	this->changeColor(LIGHT_BLUE);
	this->gotoxy(this->getPlayer()->getxPos(), this->getPlayer()->getyPos()); // place console cursor on certain pos
	cout << "I";
	this->changeColor(WHITE);
}

void GameManagement::clearCell(int xPos, int yPos)
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
				this->clearCell(xPos, yPos);

				this->drawPlayer();
				Sleep(200);
			}

		}

		else if (GetKeyState('D') & 0x8000) {
			if (this->checkIfCollision(xPos + 1, yPos) != 0) {
				this->player->setxPos(xPos + 1);
				this->clearCell(xPos, yPos);
				this->drawPlayer();
				Sleep(200);
			}

		}
		else if (GetKeyState('W') & 0x8000) {
			if (this->checkIfCollision(xPos, yPos - 1) != 0) {
				this->player->setyPos(yPos - 1);
				this->clearCell(xPos, yPos);
				this->drawPlayer();
				Sleep(200);
			}
		}
		else if (GetKeyState('S') & 0x8000) {
			if (this->checkIfCollision(xPos, yPos + 1) != 0) {
				this->player->setyPos(yPos + 1);
				this->clearCell(xPos, yPos);
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

void GameManagement::moveBullet(Cannon* cannon, int xMove, int yMove)
{
	vector<string> boardASCII = this->board->getBoardASCII();
	// Move Vertically
	if (yMove != 0 && xMove == 0) {
		for (int y = cannon->getYPos(); y < boardASCII.size(); y++) {
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && checkIfCollision(cannon->getXPos(), y + yMove) == -1) {
				this->clearCell(cannon->getXPos(), y);
				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

				this->drawBullet(cannon->getXPos(), y + yMove);
				break;
			}
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && checkIfCollision(cannon->getXPos(), y + yMove) == 0) {
				this->clearCell(cannon->getXPos(), y);
				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->initBullet(cannon, xMove, yMove);

				this->drawBullet(cannon->getXPos(), cannon->getYPos() + yMove);
			}
		}
	}
	// Move Horizontally
	else if (xMove != 0 && yMove == 0) {
		for (int x = cannon->getXPos(); x < boardASCII.at(0).size(); x++) {
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && checkIfCollision(x + xMove, cannon->getYPos()) == -1) {
				this->clearCell(x, cannon->getYPos());
				this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
				this->board->modifyBoardASCII(x + xMove, cannon->getYPos(), 'o');

				this->drawBullet(x + xMove, cannon->getYPos());
				break;
			}
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && checkIfCollision(x + xMove, cannon->getYPos()) == 0) {
				this->clearCell(x, cannon->getYPos());
				this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
				this->initBullet(cannon, xMove, yMove);

				this->drawBullet(cannon->getXPos() + xMove, cannon->getYPos());
			}
		}
	}
}

void GameManagement::drawBullet(int xPos, int yPos) {
	this->changeColor(RED);
	this->gotoxy(xPos, yPos);
	cout << this->cannons.at(0)->getReprBullet();
	this->changeColor(WHITE);
}


void GameManagement::initBullet(Cannon* cannon, int xMove, int yMove) {
	this->board->modifyBoardASCII(cannon->getXPos() + xMove, cannon->getYPos() + yMove, 'o');

}

void GameManagement::shootCannonSlow() {
	while (true) {
		for (auto cannon : this->cannons) {
			if(cannon->getShootDelay() >= 500 && cannon->getShootDir() == 'D') this->moveBullet(cannon, 0, 1);
			else if(cannon->getShootDelay() >= 500 && cannon->getShootDir() == 'U') this->moveBullet(cannon, 0, -1);
			else if(cannon->getShootDelay() >= 500 && cannon->getShootDir() == 'R') this->moveBullet(cannon, 1, 0);
			else if(cannon->getShootDelay() >= 500 && cannon->getShootDir() == 'L') this->moveBullet(cannon, -1, 0);
		}
		Sleep(300);
	}
}


void GameManagement::shootCannonFast() {
	Sleep(200);
}

Board* GameManagement::getBoard() const
{
	return this->board;
}

vector<Cannon*> GameManagement::getCannons() const
{
	return this->cannons;
}

Player* GameManagement::getPlayer() const
{
	return this->player;
}
