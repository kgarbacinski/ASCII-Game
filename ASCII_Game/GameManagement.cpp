#include "GameManagement.h"

GameManagement* GameManagement::instance = nullptr;

GameManagement::GameManagement() {
}

void GameManagement::drawShotObjects()
{
	for (auto cannon : this->shootableObjects) {
		this->changeColor(DARK_RED);
		this->gotoxy(cannon->getXPos(), cannon->getYPos());
		cannon->drawObject();
		this->changeColor(WHITE);
	}
}

void GameManagement::putShotObjects() {
	for (auto cannon : this->shootableObjects) {
		this->board->modifyBoardASCII(cannon->getXPos(), cannon->getYPos(), 'c');
	}
}

void GameManagement::putMovObjects()
{
	for (auto dollar : this->movableObjects) {
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

vector<Object*>::iterator GameManagement::findAt(const int& xPos, const int& yPos) {
	return find_if(this->ats.begin(), this->ats.end(), [xPos, yPos](Object* at) { return at->getXPos() == xPos && at->getYPos() == yPos; });
}

bool GameManagement::moveAt(Object* at, const int& xDir, const int& yDir) {
	int xPos = at->getXPos(), yPos = at->getYPos();

	if (checkIfCollision(xPos + xDir, yPos + yDir) != CollisionState::WALL && 
		checkIfCollision(xPos + xDir, yPos + yDir) != CollisionState::AT &&
		this->board->getBoardASCII().at(yPos + yDir).at(xPos + xDir) != 'c' &&
		this->board->getBoardASCII().at(yPos + yDir).at(xPos + xDir) != '$') {
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

const vector<Object*>& GameManagement::getAts() const
{
	return this->ats;
}

void GameManagement::movePlayer()
{	
	int xPos = this->player->getxPos(), yPos = this->player->getyPos();

	if (GetKeyState('A') & 0x8000) {
		if (this->checkIfCollision(xPos - 1, yPos) == CollisionState::EMPTY_FIELD) { // player on the wall
			this->clearCell(xPos, yPos);

			this->board->modifyBoardASCII(xPos, yPos, ' ');

			this->player->setxPos(xPos - 1);

			this->putPlayer();
		}
		else if (this->checkIfCollision(xPos - 1, yPos) == CollisionState::DEATH) { // player's death
			this->killPlayer();
		}
		else if (this->checkIfCollision(xPos - 1, yPos) == CollisionState::AT) { // next field contains at
			vector<Object*>::iterator it = this->findAt(xPos - 1, yPos);
			if (it != this->ats.end() && this->moveAt(*it, -1, 0)) {
				this->clearCell(xPos, yPos);
				this->board->modifyBoardASCII(xPos, yPos, ' ');
				this->player->setxPos(xPos - 1);

				this->putPlayer();
			}
		}
	}

	else if (GetKeyState('D') & 0x8000) {
		if (this->checkIfCollision(xPos + 1, yPos) == CollisionState::EMPTY_FIELD) {
			this->clearCell(xPos, yPos);

			this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

			this->player->setxPos(xPos + 1);

			this->putPlayer();
		}
		else if (this->checkIfCollision(xPos + 1, yPos) == CollisionState::DEATH) {
			this->killPlayer();
		}
		else if (this->checkIfCollision(xPos + 1, yPos) == CollisionState::AT) { // next field contains at
			vector<Object*>::iterator it = this->findAt(xPos + 1, yPos);
			if (it != this->ats.end() && this->moveAt(*it, 1, 0)) {
				this->clearCell(xPos, yPos);
				this->board->modifyBoardASCII(xPos, yPos, ' ');
				this->player->setxPos(xPos + 1);

				this->putPlayer();
			}
		}

	}
	else if (GetKeyState('W') & 0x8000) {
		if (this->checkIfCollision(xPos, yPos - 1) == CollisionState::EMPTY_FIELD) {
			this->clearCell(xPos, yPos);

			this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

			this->player->setyPos(yPos - 1);
			this->putPlayer();
		}
		else if (this->checkIfCollision(xPos, yPos - 1) == CollisionState::DEATH) {
			this->killPlayer();
		}
		else if (this->checkIfCollision(xPos, yPos - 1) == CollisionState::AT) { // next field contains at
			vector<Object*>::iterator it = this->findAt(xPos, yPos - 1);
			if (it != this->ats.end() && this->moveAt(*it, 0, -1)) {
				this->clearCell(xPos, yPos);
				this->board->modifyBoardASCII(xPos, yPos, ' ');
				this->player->setyPos(yPos - 1);

				this->putPlayer();
			}
		}
	}
	else if (GetKeyState('S') & 0x8000) {
		if (this->checkIfCollision(xPos, yPos + 1) == CollisionState::EMPTY_FIELD) {
			this->clearCell(xPos, yPos);

			this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');

			this->player->setyPos(yPos + 1);
			this->putPlayer();
		}
		else if (this->checkIfCollision(xPos, yPos + 1) == CollisionState::DEATH) {
			this->killPlayer();
		}
		else if (this->checkIfCollision(xPos, yPos + 1) == CollisionState::AT) { // next field contains at
			vector<Object*>::iterator it = this->findAt(xPos, yPos + 1);
			if (it != this->ats.end() && this->moveAt(*it, 0, 1)) {
				this->clearCell(xPos, yPos);
				this->board->modifyBoardASCII(xPos, yPos, ' ');
				this->player->setyPos(yPos + 1);

				this->putPlayer();
			}
		}
	}
}

CollisionState GameManagement::checkIfCollision(const int& newXPos, const int& newYPos)
{
	// 0 sciana
	// 9 death
	// 1 at
	// -1 wall
	vector<string> boardASCII = this->board->getBoardASCII();
	// Check wall
	if (boardASCII.at(newYPos).at(newXPos) == '#' ||
		boardASCII.at(newYPos).at(newXPos) == 'c') {
		return CollisionState::WALL; // dla sciany
	}
	if (boardASCII.at(newYPos).at(newXPos) == 'o' ||
		boardASCII.at(newYPos).at(newXPos) == 'p' ||
		boardASCII.at(newYPos).at(newXPos) == '$') {

		return CollisionState::DEATH; // player's death 
	}
	if (boardASCII.at(newYPos).at(newXPos) == '@') {
		return CollisionState::AT; // for at
	}

	return CollisionState::EMPTY_FIELD; // empty field
}

void GameManagement::moveBullet(ShootableObject* cannon, const int& xMove, const int& yMove)
{
	vector<string> boardASCII = this->board->getBoardASCII();
	// Move Vertically
	if (yMove != 0 && xMove == 0) {
		int y;
		for (y = cannon->getYPos() + yMove; boardASCII.at(y).at(cannon->getXPos()) != 'o'; y++) {
			if (boardASCII.at(y).at(cannon->getXPos()) == '#') {
				this->initBullet(cannon, xMove, yMove);
				return;
			}
		}
		// For Empty Field
		if (checkIfCollision(cannon->getXPos(), y + yMove) == CollisionState::EMPTY_FIELD) {
			this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
			this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

			this->clearCell(cannon->getXPos(), y);
			this->drawBullet(cannon->getXPos(), y + yMove);
		
		}
		// For Player
		else if (checkIfCollision(cannon->getXPos(), y + yMove) == CollisionState::DEATH) {
			this->killPlayer();

			this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
			this->board->modifyBoardASCII(cannon->getXPos(), y + yMove, 'o');

			this->clearCell(cannon->getXPos(), y);
			this->drawBullet(cannon->getXPos(), y + yMove);
		}

		// For Wall
		else if ((checkIfCollision(cannon->getXPos(), y + yMove) == CollisionState::WALL ||
			checkIfCollision(cannon->getXPos(), y + yMove) == CollisionState::AT)) {
			this->board->modifyBoardASCII(cannon->getXPos(), y, ' ');
			this->initBullet(cannon, xMove, yMove);

			this->clearCell(cannon->getXPos(), y);
			this->drawBullet(cannon->getXPos(), cannon->getYPos() + yMove);
		}
	}
	// Move Horizontally
	else if (xMove != 0 && yMove == 0) {
		int x;
		for (x = cannon->getXPos() + xMove; boardASCII.at(cannon->getYPos()).at(x) != 'o'; x++) {
			if (boardASCII.at(cannon->getYPos()).at(x) == '#') {
				this->initBullet(cannon, xMove, yMove);
				return;
			}
		}

		if (checkIfCollision(x + xMove, cannon->getYPos()) == CollisionState::EMPTY_FIELD) {
			this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
			this->board->modifyBoardASCII(x + xMove, cannon->getYPos(), 'o');

			this->clearCell(x, cannon->getYPos());
			this->drawBullet(x + xMove, cannon->getYPos());
		}
		else if (checkIfCollision(x + xMove, cannon->getYPos()) == CollisionState::DEATH) {
			this->killPlayer();

			this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
			this->board->modifyBoardASCII(x + xMove, cannon->getYPos(), 'o');

			this->clearCell(x, cannon->getYPos());
			this->drawBullet(x + xMove, cannon->getYPos());
		}
		else if ((checkIfCollision(x + xMove, cannon->getYPos()) == CollisionState::WALL ||
			checkIfCollision(x + xMove, cannon->getYPos()) == CollisionState::AT)) {
			this->board->modifyBoardASCII(x, cannon->getYPos(), ' ');
			this->initBullet(cannon, xMove, yMove);

			this->clearCell(x, cannon->getYPos());
			this->drawBullet(cannon->getXPos() + xMove, cannon->getYPos());
		}
	}
}

void GameManagement::drawBullet(const int& xPos, const int& yPos) {
	this->changeColor(RED);
	this->gotoxy(xPos, yPos);

	cout << this->shootableObjects.at(0)->getReprBullet();
	this->changeColor(WHITE);
}


void GameManagement::initBullet(ShootableObject* cannon, const int& xMove, const int& yMove) {
	if (checkIfCollision(cannon->getXPos() + xMove, cannon->getYPos() + yMove) == CollisionState::EMPTY_FIELD) {
		this->board->modifyBoardASCII(cannon->getXPos() + xMove, cannon->getYPos() + yMove, 'o');
	}
}

void GameManagement::shootCannon(long long mcr) {
	for (auto cannon : this->shootableObjects) {
		if (cannon->getShootDir() == 'D' && cannon->getShootDelay() == mcr) { this->moveBullet(cannon, 0, 1); }
		else if (cannon->getShootDir() == 'U' && cannon->getShootDelay() == mcr) { this->moveBullet(cannon, 0, -1); }
		else if ( cannon->getShootDir() == 'R' && cannon->getShootDelay() == mcr) { this->moveBullet(cannon, 1, 0); }
		else if (cannon->getShootDir() == 'L' && cannon->getShootDelay() == mcr) { this->moveBullet(cannon, -1, 0); }
	}
}

void GameManagement::drawMovObjects()
{
	for (auto dollar : this->movableObjects) {
		this->changeColor(LIGHT_GREEN);
		this->gotoxy(dollar->getXPos(), dollar->getYPos());
		dollar->drawObject();
		this->changeColor(WHITE);
	}
}

void GameManagement::moveDollars()
{
	for (auto dollar : this->movableObjects) {
		int xPos = dollar->getXPos(), yPos = dollar->getYPos();
		
		if (this->checkIfCollision(xPos + dollar->getXDir(), yPos) == CollisionState::WALL) { // wall is next
			dollar->setXDir(dollar->getXDir() * (-1)); // change dir
		}
		else if (this->checkIfCollision(xPos + dollar->getXDir(), yPos) == CollisionState::DEATH) {
			this->killPlayer();
		}

		dollar->setXPos(xPos + dollar->getXDir());
		this->clearCell(xPos, yPos);
		this->board->modifyBoardASCII(xPos, yPos, ' ');
		this->board->modifyBoardASCII(xPos + dollar->getXDir(), yPos, '$');
	}

	this->drawMovObjects();
}

void GameManagement::putAt(Object* at) {
	this->board->modifyBoardASCII(at->getXPos(), at->getYPos(), '@');
}

void GameManagement::drawAt(Object* at) {
	this->changeColor(GRAY);
	this->gotoxy(at->getXPos(), at->getYPos());
	at->drawObject();
	this->changeColor(WHITE);
}

Board* GameManagement::getBoard() const
{
	return this->board;
}

vector<ShootableObject*> GameManagement::getCannons() const
{
	return this->shootableObjects;
}

Player* GameManagement::getPlayer() const
{
	return this->player;
}
