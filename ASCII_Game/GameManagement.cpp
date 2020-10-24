#include "GameManagement.hpp"

GameManagement* GameManagement::instance = nullptr;

void GameManagement::addCannonToShootableObjVector(int _xPos, int _yPos, int _timeDelay, bool _isVer, char _shootDir)
{
	this->shootableObjects.push_back(this->shootableObjectFactory->createCannon(_xPos, _yPos, _timeDelay, _isVer, _shootDir));
}

void GameManagement::addPercentToMoveableObjVector(int _xPos, int _yPos, int _xStart, int _xEnd, int _yStart, int _yEnd)
{
	this->movableObjects.push_back(this->movableObjectFactory->createPercent(_xPos, _yPos, _xStart, _xEnd, _yStart, _yEnd));
}

void GameManagement::addDollarToMoveableObjVector(int _xPos, int _yPos, char _moveDir)
{
	this->movableObjects.push_back(this->movableObjectFactory->createDollar(_xPos, _yPos, _moveDir));
}

GameManagement::GameManagement() {
	/* ADD SHOOTABLE OBJECTS */
	this->addCannonToShootableObjVector(5, 25, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(5, 15, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(11, 28, timeDelay::CANNON_SLOW, false, 'R');

	this->addCannonToShootableObjVector(26, 29, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(27, 29, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(28, 29, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(29, 29, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(31, 29, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(32, 29, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(33, 29, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(34, 29, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(35, 29, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(36, 29, timeDelay::CANNON_FAST, true, 'D');

	this->addCannonToShootableObjVector(41, 36, timeDelay::CANNON_SLOW, true, 'U');
	this->addCannonToShootableObjVector(43, 36, timeDelay::CANNON_FAST, true, 'U');
	this->addCannonToShootableObjVector(45, 36, timeDelay::CANNON_FAST, true, 'U');
	this->addCannonToShootableObjVector(47, 36, timeDelay::CANNON_SLOW, true, 'U');

	this->addCannonToShootableObjVector(58,25, timeDelay::CANNON_SLOW, false, 'L');
	this->addCannonToShootableObjVector(58,24, timeDelay::CANNON_SLOW, false, 'L');
	this->addCannonToShootableObjVector(58,23, timeDelay::CANNON_SLOW, false, 'L');

	this->addCannonToShootableObjVector(18,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(19,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(20,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(21,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(22,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(23,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(24,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(25,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(26,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(27,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(28,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(29,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(30,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(31,8, timeDelay::CANNON_SLOW, true, 'D');
	this->addCannonToShootableObjVector(32,8, timeDelay::CANNON_SLOW, true, 'D');

	this->addCannonToShootableObjVector(54,33, timeDelay::CANNON_SLOW, false, 'L');
	this->addCannonToShootableObjVector(54,29, timeDelay::CANNON_SLOW, false, 'L');

	this->addCannonToShootableObjVector(17,1, timeDelay::CANNON_FAST, false, 'R');
	this->addCannonToShootableObjVector(17,2, timeDelay::CANNON_FAST, false, 'R');
	this->addCannonToShootableObjVector(17,3, timeDelay::CANNON_FAST, false, 'R'); 
	this->addCannonToShootableObjVector(17, 4, timeDelay::CANNON_FAST, false, 'R');
	this->addCannonToShootableObjVector(17,5, timeDelay::CANNON_FAST, false, 'R');
	this->addCannonToShootableObjVector(17,6, timeDelay::CANNON_FAST, false, 'R');

	this->addCannonToShootableObjVector(85,2, timeDelay::CANNON_FAST, false, 'L');
	this->addCannonToShootableObjVector(85,3, timeDelay::CANNON_FAST, false, 'L');
	this->addCannonToShootableObjVector(85,4, timeDelay::CANNON_FAST, false, 'L');
	this->addCannonToShootableObjVector(85,5, timeDelay::CANNON_FAST, false, 'L');
	this->addCannonToShootableObjVector(85,6, timeDelay::CANNON_FAST, false, 'L');
	this->addCannonToShootableObjVector(85,7, timeDelay::CANNON_FAST, false, 'L');

	this->addCannonToShootableObjVector(83,1, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(82,1, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(81,1, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(80,1, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(79,1, timeDelay::CANNON_FAST, true, 'D');
	this->addCannonToShootableObjVector(78,1, timeDelay::CANNON_FAST, true, 'D');

	this->addCannonToShootableObjVector(14,26, timeDelay::CANNON_FAST, true, 'U');

	this->addCannonToShootableObjVector(47,15, timeDelay::CANNON_FAST, true, 'D');




	/* ADD MOVEABLE OBJECTS */
	this->addDollarToMoveableObjVector(10, 31, 'L');
	this->addDollarToMoveableObjVector(10, 33, 'R');
	
	this->addDollarToMoveableObjVector(8, 2, 'R');
	this->addDollarToMoveableObjVector(10, 2, 'L');

	this->addDollarToMoveableObjVector(8, 3, 'L');
	this->addDollarToMoveableObjVector(10, 3, 'R');
	this->addDollarToMoveableObjVector(12, 3, 'L');

	this->addDollarToMoveableObjVector(8, 4, 'L');
	this->addDollarToMoveableObjVector(10, 4, 'R');

	this->addDollarToMoveableObjVector(10, 5, 'R');

	this->addDollarToMoveableObjVector(46, 33,'R');
	this->addDollarToMoveableObjVector(46, 31,'L');
	this->addDollarToMoveableObjVector(46, 29,'R');

	this->addDollarToMoveableObjVector(48, 34,'R');

	this->addDollarToMoveableObjVector(70, 11, 'L');
	this->addDollarToMoveableObjVector(68, 11, 'R');

	this->addDollarToMoveableObjVector(70,12 ,'R');

	this->addDollarToMoveableObjVector(70,13 ,'R');
	this->addDollarToMoveableObjVector(68,13 ,'L');

	

	this->addPercentToMoveableObjVector(19, 32, 14, 22, 29, 37);
	this->addPercentToMoveableObjVector(20, 32, 14, 22, 29, 37);

	this->addPercentToMoveableObjVector(28, 20, 23, 36, 17, 28);
	this->addPercentToMoveableObjVector(28, 20, 23, 36, 17, 28);
	this->addPercentToMoveableObjVector(28, 20, 23, 36, 17, 28);
	this->addPercentToMoveableObjVector(28, 20, 23, 36, 17, 28);
	
	// ADD ATS
	this->ats.push_back(new At(56, 26));
	this->ats.push_back(new At(12, 29))
		;
	this->ats.push_back(new At(1, 13));
	this->ats.push_back(new At(4, 13));
	this->ats.push_back(new At(6, 13));

	this->ats.push_back(new At(2, 12));
	this->ats.push_back(new At(4, 12));
	this->ats.push_back(new At(6, 12));
	this->ats.push_back(new At(11, 12));

	this->ats.push_back(new At(2, 11));
	this->ats.push_back(new At(3, 11));
	this->ats.push_back(new At(4, 11));
	this->ats.push_back(new At(7, 11));

	this->ats.push_back(new At(2, 10));
	this->ats.push_back(new At(5, 10));
	this->ats.push_back(new At(8, 10));

	this->ats.push_back(new At(1, 9));
	this->ats.push_back(new At(4, 9));
	this->ats.push_back(new At(9, 9));
	this->ats.push_back(new At(11, 9));

	this->ats.push_back(new At(3, 8));
	this->ats.push_back(new At(10, 8));

	// Create checkpoints
	//this->checkpointsStack.push(make_pair(4, 23));
	this->checkpointsStack.push(make_pair(2, 34));
	this->checkpointsStack.push(make_pair(1, 34));
		
}

GameManagement::~GameManagement()
{
	delete this->shootableObjectFactory;
	delete this->movableObjectFactory;
	delete this->board;
	delete this->player;
	for (auto& v : this->movableObjects) {
		delete v;
	}
	
	for (auto& v : this->shootableObjects) {
		delete v;
	}
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
	cout << this->player->getRepr();
	this->changeColor(WHITE);
}

void GameManagement::killPlayer()
{
	this->clearCell(this->player->getxPos(), this->player->getyPos());
	this->board->modifyBoardASCII(this->player->getxPos(), this->player->getyPos(), ' ');
	this->player->setxPos(this->player->getXCheckpoint());
	this->player->setyPos(this->player->getYCheckpoint());
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

vector<Object*>::iterator GameManagement::findAt(int xPos, int yPos) {
	return find_if(this->ats.begin(), this->ats.end(), [xPos, yPos](Object* at) { return at->getXPos() == xPos && at->getYPos() == yPos; });
}

bool GameManagement::moveAt(Object* at, int xDir, int yDir) {
	int xPos = at->getXPos(), yPos = at->getYPos();

	if (checkIfCollision(xPos + xDir, yPos + yDir, '@') != CollisionState::WALL && 
		checkIfCollision(xPos + xDir, yPos + yDir, '@') != CollisionState::AT &&
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

void GameManagement::handleKeyboardInput()
{
	if (GetKeyState('A') & 0x8000) {
		movePlayer(-1, 0);
	}
	else if (GetKeyState('D') & 0x8000) {
		movePlayer(1, 0);
	}
	else if (GetKeyState('W') & 0x8000) {
		movePlayer(0, -1);
	}
	else if (GetKeyState('S') & 0x8000) {
		movePlayer(0, 1);
	}
	else if (GetKeyState(VK_SPACE) & 0x8000) {
		movePlayer(0, 1);
	}
}

void GameManagement::moveIntoNextField(int deltaX, int deltaY) {
	int xPos = this->player->getXPos();
	int yPos = this->player->getYPos();

	char repr = '<';
	if (deltaX == 1 && deltaY == 0) repr = '>';
	else if (deltaX == 0 && deltaY == -1) repr = char(24);
	else if (deltaX == 0 && deltaY == 1) repr = char(25);

	this->clearCell(xPos, yPos);

	this->board->modifyBoardASCII(xPos, yPos, ' ');

	this->player->setRepr(repr);

	this->player->setxPos(xPos + deltaX);
	this->player->setyPos(yPos + deltaY);

	this->putPlayer();
}

void GameManagement::movePlayer(int deltaX, int deltaY)
{	
	int xPos = this->player->getxPos(), yPos = this->player->getyPos();

	if (this->checkIfCollision(xPos + deltaX, yPos + deltaY, 'p') == CollisionState::EMPTY_FIELD) { // player on the wall
		this->moveIntoNextField(deltaX, deltaY);			
	}
	else if (this->checkIfCollision(xPos + deltaX, yPos + deltaY, 'p') == CollisionState::DEATH) { // player's death
		this->killPlayer();
	}
	else if (this->checkIfCollision(xPos + deltaX, yPos + deltaY, 'p') == CollisionState::AT) { // next field contains at
		vector<Object*>::iterator it = this->findAt(xPos + deltaX, yPos + deltaY);
			
		if (it != this->ats.end() && this->moveAt(*it, deltaX, deltaY)) {

			this->clearCell(xPos, yPos);
			this->board->modifyBoardASCII(xPos, yPos, ' ');
			this->player->setxPos(xPos + deltaX);
			this->player->setyPos(yPos + deltaY);

			this->putPlayer();
		}
	}

	if (this->checkIfCheckpoint(xPos + deltaX, yPos + deltaY)) {
		int x = this->checkpointsStack.top().first, y = this->checkpointsStack.top().second;
		this->checkpointsStack.pop();
		this->player->setCheckpoint(x, y);
	}
	
}
void GameManagement::playerAttack() {
	switch (this->player->getRepr()) {
		case '<':

			return;
	}
}

CollisionState GameManagement::checkIfCollision(int newXPos, int newYPos, char currType)
{
	vector<string> boardASCII = this->board->getBoardASCII();
	// Check wall
	if (boardASCII.at(newYPos).at(newXPos) == '#' ||
		boardASCII.at(newYPos).at(newXPos) == 'c') {
		return CollisionState::WALL; // dla sciany
	}
	if ((boardASCII.at(newYPos).at(newXPos) == 'o') && (currType != 'o') ||
		(boardASCII.at(newYPos).at(newXPos) == 'p') && (currType != 'p') ||
		(boardASCII.at(newYPos).at(newXPos) == '$' && currType != '$') || 
		(boardASCII.at(newYPos).at(newXPos) == '%' && currType != '%')) {

		return CollisionState::DEATH; // player's death 
	}
	if (boardASCII.at(newYPos).at(newXPos) == '@') {
		return CollisionState::AT; // for at
	}

	return CollisionState::EMPTY_FIELD; // empty field
}

bool GameManagement::checkIfCheckpoint(int newXPos, int newYPos)
{
	if (!this->checkpointsStack.empty() && newXPos == this->checkpointsStack.top().first &&
		newYPos == this->checkpointsStack.top().second) {
		return true;
	}
	return false;
}

void GameManagement::handleShootableObjectBullet(ShootableObject* cannon, int xToHandle, int yToHandle, int deltaX, int deltaY) {
	auto modifyBoardAndScreen = [this, xToHandle, yToHandle, deltaX, deltaY]() mutable {
		this->board->modifyBoardASCII(xToHandle, yToHandle, ' ');
		this->board->modifyBoardASCII(xToHandle + deltaX, yToHandle + deltaY, 'o');

		this->clearCell(xToHandle, yToHandle);
		this->drawBullet(xToHandle + deltaX, yToHandle + deltaY);
	};

	if (checkIfCollision(xToHandle + deltaX, yToHandle + deltaY, 'o') == CollisionState::EMPTY_FIELD) {
		modifyBoardAndScreen();
	}
	else if (checkIfCollision(xToHandle + deltaX, yToHandle + deltaY, 'o') == CollisionState::DEATH) {
		this->killPlayer();

		modifyBoardAndScreen();
	}
	else if ((checkIfCollision(xToHandle + deltaX, yToHandle + deltaY, 'o') == CollisionState::WALL ||
		checkIfCollision(xToHandle + deltaX, yToHandle + deltaY, 'o') == CollisionState::AT)) {
		
		this->board->modifyBoardASCII(xToHandle, yToHandle, ' ');
		this->clearCell(xToHandle, yToHandle);
		this->initBullet(cannon, deltaX, deltaY);

		this->drawBullet(cannon->getXPos() + deltaX, cannon->getYPos() + deltaY);
	}
}

void GameManagement::moveBulletVertically(ShootableObject* cannon, int deltaX, int deltaY) {
	vector<string> boardASCII = this->board->getBoardASCII();

	int y;
	for (y = cannon->getYPos() + deltaY; boardASCII.at(y).at(cannon->getXPos()) != 'o'; y += deltaY) {
		if (boardASCII.at(y).at(cannon->getXPos()) == '#') {
			this->initBullet(cannon, deltaX, deltaY);
			return;
		}
	}

	handleShootableObjectBullet(cannon, cannon->getXPos(), y, deltaX, deltaY);
}

void GameManagement::moveBulletHorizontally(ShootableObject* cannon, int deltaX, int deltaY) {
	vector<string> boardASCII = this->board->getBoardASCII();

	int x = cannon->getXPos() + deltaX;
	while (boardASCII.at(cannon->getYPos()).at(x) != 'o') {
		if (boardASCII.at(cannon->getYPos()).at(x) == '#') {
			this->initBullet(cannon, deltaX, deltaY);
			return;
		}

		x += deltaX;
	}

	handleShootableObjectBullet(cannon, x, cannon->getYPos(), deltaX, deltaY);	
}

void GameManagement::moveBullet(ShootableObject* cannon, int deltaX, int deltaY)
{
	// Move Vertically
	if (deltaY != 0 && deltaX == 0) {
		moveBulletVertically(cannon, deltaX, deltaY);
	}
	// Move Horizontally
	else if (deltaX != 0 && deltaY == 0) {
		moveBulletHorizontally(cannon, deltaX, deltaY);
	}
}

void GameManagement::drawBullet(int xPos, int yPos) {
	this->changeColor(RED);
	this->gotoxy(xPos, yPos);

	cout << this->shootableObjects.at(0)->getReprBullet();
	this->changeColor(WHITE);
}


void GameManagement::initBullet(ShootableObject* cannon, int xMove, int yMove) {
	if (checkIfCollision(cannon->getXPos() + xMove, cannon->getYPos() + yMove, 'o') == CollisionState::EMPTY_FIELD) {
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
	for (auto object : this->movableObjects) {
		if(dynamic_cast<Dollar*>(object) != nullptr) this->changeColor(LIGHT_GREEN);
		else if(dynamic_cast<Percent*>(object) != nullptr) this->changeColor(PURPLE);

		this->gotoxy(object->getXPos(), object->getYPos());
		object->drawObject();
		this->changeColor(WHITE);
	}
}

void GameManagement::drawCheckpoints()
{
	auto stackCopy = this->checkpointsStack;

	while (!stackCopy.empty()) {
		auto pair = stackCopy.top();
		this->gotoxy(pair.first, pair.second);
		cout << 'C';
		stackCopy.pop();
	}
}

void GameManagement::moveObjects()
{
	for (auto object : this->movableObjects) {
			int xPos = object->getXPos(), yPos = object->getYPos();
			
			//unique_ptr<CollisionState(GameManagement::*)(const int&, const int&)> ptr(&checkIfCollision);

			if (this->checkIfCollision(xPos + object->getXDir(), yPos + object->getYDir(), object->getRepr()) == CollisionState::WALL) { // wall is next
				object->setXDir(object->getXDir() * (-1));
			}
			else if (this->checkIfCollision(xPos + object->getXDir(), yPos + object->getYDir(), object->getRepr()) == CollisionState::DEATH) {
				this->killPlayer();
			}

			object->moveObject();
			this->clearCell(xPos, yPos);
			this->board->modifyBoardASCII(xPos, yPos, ' ');
			this->board->modifyBoardASCII(xPos + object->getXDir(), yPos + object->getYDir(), object->getRepr());	
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
