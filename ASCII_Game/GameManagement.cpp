#include "GameManagement.h"

GameManagement* GameManagement::instance = nullptr;

GameManagement::GameManagement() {}

void GameManagement::drawCannons()
{
	for (auto cannon : this->cannons) {
		this->changeColor(DARK_RED);
		this->gotoxy(cannon->getXPos(), cannon->getYPos());
		if (cannon->getIsVer()) cout << cannon->getReprVer();
		else cout << cannon->getReprHor();
		this->changeColor(WHITE);
	}
}

void GameManagement::putCannons() {
	for (auto cannon : this->cannons) {
		this->board->modifyBoardASCII(cannon->getXPos(), cannon->getYPos(), 'c');
	}
}

void GameManagement::putDollars()
{
	for (auto dollar : this->dollars) {
		this->board->modifyBoardASCII(dollar->getXPos(), dollar->getYPos(), '$');
	}
}


void GameManagement::putPlayer()
{
	this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), 'p');
	this->drawPlayer();
}

void GameManagement::drawPlayer() {
	// Drawing a player
	this->changeColor(LIGHT_BLUE);
	this->gotoxy(this->getPlayer()->getxPos(), this->getPlayer()->getyPos()); // place console cursor on certain pos
	cout << 'I';
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

void GameManagement::clearCell(const int& xPos, const int& yPos)
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

vector<At*>::iterator GameManagement::findAt(const int& xPos, const int& yPos) {
	return find_if(this->ats.begin(), this->ats.end(), [xPos, yPos](At* at) { return at->getXPos() == xPos && at->getYPos() == yPos; });
}

bool GameManagement::moveAt(At* at, const int& xDir, const int& yDir) {
	int xPos = at->getXPos(), yPos = at->getYPos();

	if (checkIfCollision(xPos + xDir, yPos + yDir) != 0) {
		this->clearCell(xPos, yPos);

		this->board->modifyBoardASCII(xPos, yPos, ' ');

		at->setXPos(xPos + xDir);
		at->setYPos(yPos + yDir);

		this->putAt(at);
		this->drawAt(at);

		return true;
	}

	return false;
	

}

const vector<At*>& GameManagement::getAts() const
{
	return this->ats;
}

void GameManagement::movePlayer()
{
	while (true) {
		int xPos = this->player->getxPos(), yPos = this->player->getyPos();

		if (GetKeyState('A') & 0x8000) {
			if (this->checkIfCollision(xPos - 1, yPos) == -1) { // player on the wall
				this->clearCell(xPos, yPos);

				this->board->modifyBoardASCII(xPos, yPos, ' ');

				this->player->setxPos(xPos - 1);

				this->putPlayer();
				Sleep(200);
			}
			else if (this->checkIfCollision(xPos - 1, yPos) == 9) { // player's death
				this->killPlayer();
				Sleep(200);
			}
			else if (this->checkIfCollision(xPos - 1, yPos) == 1) { // next field contains at
				vector<At*>::iterator it = this->findAt(xPos - 1, yPos);
				if (it != this->ats.end() && this->moveAt(*it, -1, 0)) {
					this->clearCell(xPos, yPos);
					this->board->modifyBoardASCII(xPos, yPos, ' ');
					this->player->setxPos(xPos - 1);

					this->putPlayer();
					Sleep(200);
				}
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
			else if (this->checkIfCollision(xPos + 1, yPos) == 1) { // next field contains at
				vector<At*>::iterator it = this->findAt(xPos + 1, yPos);
				if (it != this->ats.end() && this->moveAt(*it, 1, 0)) {
					this->clearCell(xPos, yPos);
					this->board->modifyBoardASCII(xPos, yPos, ' ');
					this->player->setxPos(xPos + 1);

					this->putPlayer();
					Sleep(200);
				}
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
			else if (this->checkIfCollision(xPos, yPos - 1) == 1) { // next field contains at
				vector<At*>::iterator it = this->findAt(xPos, yPos - 1);
				if (it != this->ats.end() && this->moveAt(*it, 0, -1)) {
					this->clearCell(xPos, yPos);
					this->board->modifyBoardASCII(xPos, yPos, ' ');
					this->player->setyPos(yPos - 1);

					this->putPlayer();
					Sleep(200);
				}
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
			else if (this->checkIfCollision(xPos, yPos + 1) == 1) { // next field contains at
				vector<At*>::iterator it = this->findAt(xPos, yPos + 1);
				if (it != this->ats.end() && this->moveAt(*it, 0, 1)) {
					this->clearCell(xPos, yPos);
					this->board->modifyBoardASCII(xPos, yPos, ' ');
					this->player->setyPos(yPos + 1);

					this->putPlayer();
					Sleep(200);
				}
			}
		}
	}
}

int GameManagement::checkIfCollision(const int& newXPos, const int& newYPos)
{
	vector<string> boardASCII = this->board->getBoardASCII();
	// Check wall
	if (boardASCII.at(newYPos).at(newXPos) == '#' ||
		boardASCII.at(newYPos).at(newXPos) == 'c') {
		return 0; // dla sciany
	}
	if (boardASCII.at(newYPos).at(newXPos) == 'o' ||
		boardASCII.at(newYPos).at(newXPos) == 'p' || 
		boardASCII.at(newYPos).at(newXPos) == '$'){

		return 9; // player's death 
	}
	if (boardASCII.at(newYPos).at(newXPos) == '@') {
		return 1; // for at
	}

	return -1; // puste pole
}

void GameManagement::moveBullet(Cannon* cannon, const int& xMove, const int& yMove)
{
	vector<string> boardASCII = this->board->getBoardASCII();
	// Move Vertically
	if (yMove != 0 && xMove == 0) {
		for (int y = cannon->getYPos() + yMove; y < boardASCII.size(); y++) {
			// For Empty Field
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && 
				checkIfCollision(cannon->getXPos(), y + yMove) == -1) {
				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

				this->clearCell(cannon->getXPos(), y);
				this->drawBullet(cannon->getXPos(), y + yMove);
				break;
			}
			// For Player
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && 
				checkIfCollision(cannon->getXPos(), y + yMove) == 9) {
				this->killPlayer();

				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

				this->clearCell(cannon->getXPos(), y);
				this->drawBullet(cannon->getXPos(), y + yMove);
				break;
			}

			// For Wall
			if (boardASCII.at(y).at(cannon->getXPos()) == 'o' && 
				(checkIfCollision(cannon->getXPos(), y + yMove) == 0 ||
				checkIfCollision(cannon->getXPos(), y + yMove) == 1)) {
				this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
				this->initBullet(cannon, xMove, yMove);

				this->clearCell(cannon->getXPos(), y);
				this->drawBullet(cannon->getXPos(), cannon->getYPos() + yMove);
				break;
			}
		}
	}
	// Move Horizontally
	else if (xMove != 0 && yMove == 0) {
		for (int x = cannon->getXPos() + xMove; x < boardASCII.at(0).size(); x++) {
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && 
				checkIfCollision(x + xMove, cannon->getYPos()) == -1) {
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
			if (boardASCII.at(cannon->getYPos()).at(x) == 'o' && 
				(checkIfCollision(x + xMove, cannon->getYPos()) == 0 ||
				checkIfCollision(x + xMove, cannon->getYPos()) == 1)) {
				this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
				this->initBullet(cannon, xMove, yMove);

				this->clearCell(x, cannon->getYPos());
				this->drawBullet(cannon->getXPos() + xMove, cannon->getYPos());
				break;
			}
		}
	}
}

void GameManagement::drawBullet(const int& xPos, const int& yPos) {
	this->changeColor(RED);
	this->gotoxy(xPos, yPos);
	cout << this->cannons.at(0)->getReprBullet();
	this->changeColor(WHITE);
}


void GameManagement::initBullet(Cannon* cannon, const int& xMove, const int& yMove) {
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
		Sleep(500);
	}
}

void GameManagement::shootCannonFast() {
	while (true) {
		/*long long ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		if (ms % 5000) {
			for (auto cannon : this->cannons) {
				if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'D') this->initBullet(cannon, 0, 1);
				else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'U') this->initBullet(cannon, 0, -1);
				else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'R') this->initBullet(cannon, 1, 0);
				else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'L') this->initBullet(cannon, -1, 0);
			}
		}*/
		for (auto cannon : this->cannons) {
			if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'D') this->moveBullet(cannon, 0, 1);
			else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'U') this->moveBullet(cannon, 0, -1);
			else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'R') this->moveBullet(cannon, 1, 0);
			else if (cannon->getShootDelay() < 500 && cannon->getShootDir() == 'L') this->moveBullet(cannon, -1, 0);
		}
		Sleep(200);
	}
}


void GameManagement::drawDollars()
{
	for (auto dollar : this->dollars) {
		this->changeColor(LIGHT_GREEN);
		this->gotoxy(dollar->getXPos(), dollar->getYPos());
		cout << dollar->getReprVer();
		this->changeColor(WHITE);
	}
}

void GameManagement::moveDollars()
{
	while (true) {
		for (auto dollar : this->dollars) {
			int xPos = dollar->getXPos(), yPos = dollar->getYPos();
		
			if (this->checkIfCollision(xPos + dollar->getXDir(), yPos) == 0) { // wall is next
				dollar->setXDir(dollar->getXDir() * (-1)); // change dir
			}
			else if (this->checkIfCollision(xPos + dollar->getXDir(), yPos) == 9) {
				this->killPlayer();
			}

			dollar->setXPos(xPos + dollar->getXDir());
			this->clearCell(xPos, yPos);
			this->board->modifyBoardASCII(xPos, yPos, ' ');
			this->board->modifyBoardASCII(xPos + dollar->getXDir(), yPos, '$');
		}

		this->drawDollars();

		Sleep(500);
	}
}

void GameManagement::putAt(At* at) {
	this->board->modifyBoardASCII(at->getXPos(), at->getYPos(), '@');
}

void GameManagement::drawAt(At* at) {
	this->changeColor(GRAY);
	this->gotoxy(at->getXPos(), at->getYPos());
	cout << at->getReprVer();
	this->changeColor(WHITE);
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
