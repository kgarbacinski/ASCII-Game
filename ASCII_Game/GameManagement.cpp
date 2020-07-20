#include "GameManagement.h"

constexpr auto DARK_RED = 4;
constexpr auto RED = 12;
constexpr auto LIGHT_BLUE = 11;
constexpr auto WHITE = 15;

GameManagement* GameManagement::instance = nullptr;

GameManagement::GameManagement() {}


void GameManagement::drawCannons()
{
	for (auto cannon : this->cannons) {
		this->changeColor(DARK_RED);
		cannon->drawObject();
		this->changeColor(WHITE);
	}
}

void GameManagement::putCannons() {
	for (auto cannon : this->cannons) {
		board->modifyBoardASCII(cannon->getXPos(), cannon->getYPos(), 'c');
	}
}

void GameManagement::putPlayer()
{
	this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), 'p');

	// Drawing a player
	this->changeColor(LIGHT_BLUE);
	this->gotoxy(this->getPlayer()->getxPos(), this->getPlayer()->getyPos()); // place console cursor on certain pos
	cout << "I";
	this->changeColor(WHITE);
}

void GameManagement::killPlayer()
{
	this->clearCell(this->player->getxPos(), this->player->getyPos());
	this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');
	this->player->setxPos(this->player->getStartxPos());
	this->player->setyPos(this->player->getStartyPos());
	this->putPlayer();
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

		if (GetKeyState('A') & 0x8000) {
			if (this->checkIfCollision(xPos - 1, yPos) == -1) { // player on the wall
				this->clearCell(xPos, yPos);

				this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

				this->player->setxPos(xPos - 1);

				this->putPlayer();
				Sleep(200);
			}
			else if (this->checkIfCollision(xPos - 1, yPos) == 9) {
				this->killPlayer();
				Sleep(200);
			}
		}

		else if (GetKeyState('D') & 0x8000) {
			if (this->checkIfCollision(xPos + 1, yPos) == -1) {
				this->clearCell(xPos, yPos);

				this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

				this->player->setxPos(xPos + 1);

				this->putPlayer();
				Sleep(200);
			}
			else if (this->checkIfCollision(xPos + 1, yPos) == 9) {
				this->killPlayer();
				Sleep(200);
			}

		}
		else if (GetKeyState('W') & 0x8000) {
			if (this->checkIfCollision(xPos, yPos - 1) == -1) {
				this->clearCell(xPos, yPos);

				this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

				this->player->setyPos(yPos - 1);
				this->putPlayer();
				Sleep(200);
			}
			else if (this->checkIfCollision(xPos, yPos - 1) == 9) {
				this->killPlayer();
				Sleep(200);
			}
		}
		else if (GetKeyState('S') & 0x8000) {
			if (this->checkIfCollision(xPos, yPos + 1) == -1) {
				this->clearCell(xPos, yPos);

				this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

				this->player->setyPos(yPos + 1);
				this->putPlayer();
				Sleep(200);
			}
			else if (this->checkIfCollision(xPos, yPos + 1) == 9) {
				this->killPlayer();
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
	if (this->board->getBoardASCII().at(newYPos).at(newXPos) == 'o' ||
		this->board->getBoardASCII().at(newYPos).at(newXPos) == 'p'){

		return 9; // player's death 
	}

	return -1; // puste pole
}

void GameManagement::moveBullet(Cannon* cannon, int xMove, int yMove)
{
	vector<string> boardASCII = this->board->getBoardASCII();
	// Move Vertically
	if (yMove != 0 && xMove == 0) {
		for (int y = cannon->getYPos() + yMove; y < boardASCII.size(); y++) {
			// For Empty Field
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && checkIfCollision(cannon->getXPos(), y + yMove) == -1) {
				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

				this->clearCell(cannon->getXPos(), y);
				this->drawBullet(cannon->getXPos(), y + yMove);
				break;
			}
			// For Player
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && checkIfCollision(cannon->getXPos(), y + yMove) == 9) {
				this->killPlayer();

				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

				this->clearCell(cannon->getXPos(), y);
				this->drawBullet(cannon->getXPos(), y + yMove);
				break;
			}

			// For Wall
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && checkIfCollision(cannon->getXPos(), y + yMove) == 0) {
				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->initBullet(cannon, xMove, yMove);

				this->clearCell(cannon->getXPos(), y);
				this->drawBullet(cannon->getXPos(), cannon->getYPos() + yMove);
			}
		}
	}
	// Move Horizontally
	else if (xMove != 0 && yMove == 0) {
		for (int x = cannon->getXPos() + xMove; x < boardASCII.at(0).size(); x++) {
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && checkIfCollision(x + xMove, cannon->getYPos()) == -1) {
				this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
				this->board->modifyBoardASCII(x + xMove, cannon->getYPos(), 'o');

				this->clearCell(x, cannon->getYPos());
				this->drawBullet(x + xMove, cannon->getYPos());
				break;
			}
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && checkIfCollision(x + xMove, cannon->getYPos()) == 9) {
				this->killPlayer();

				this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
				this->board->modifyBoardASCII(x + xMove, cannon->getYPos(), 'o');

				this->clearCell(x, cannon->getYPos());
				this->drawBullet(x + xMove, cannon->getYPos());
				break;
			}
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && checkIfCollision(x + xMove, cannon->getYPos()) == 0) {
				this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
				this->initBullet(cannon, xMove, yMove);

				this->clearCell(x, cannon->getYPos());
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
	if (checkIfCollision(cannon->getXPos() + xMove, cannon->getYPos() + yMove) == -1) {
		this->board->modifyBoardASCII(cannon->getXPos() + xMove, cannon->getYPos() + yMove, 'o');
	}
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
	while (true) {
		for (auto cannon : this->cannons) {
			if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'D') this->moveBullet(cannon, 0, 1);
			else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'U') this->moveBullet(cannon, 0, -1);
			else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'R') this->moveBullet(cannon, 1, 0);
			else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'L') this->moveBullet(cannon, -1, 0);
		}
		Sleep(200);
	}
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
