#include <iostream>
#include <thread>   
#include "GameManagement.hpp"
#include "Cannon.hpp"
#include "Menu.hpp"
using namespace std; 

int main() {
	srand(time(NULL));

	Menu* menu = Menu::getInstance();

	menu->drawMenu();

	system("cls"); // clear menud
	/* Initializing objects */
	GameManagement* gameManager = GameManagement::getInstance();

	// put first bullets on the board
	for (auto cannon : gameManager->getCannons()) {
		if(cannon->getShootDir() == 'D') gameManager->initBullet(cannon, 0, 1);
		if(cannon->getShootDir() == 'U') gameManager->initBullet(cannon, 0, -1);
		if(cannon->getShootDir() == 'R') gameManager->initBullet(cannon, 1, 0);
		if(cannon->getShootDir() == 'L') gameManager->initBullet(cannon, -1, 0);

	}

	gameManager->drawBoard();
	gameManager->putPlayer();
	gameManager->putShotObjects(); // put on ascii board
	gameManager->drawShotObjects();
	gameManager->drawCheckpoints();
	gameManager->putMovObjects();
	gameManager->drawMovObjects();

	for (auto at : gameManager->getAts()) {
		gameManager->putAt(at);
		gameManager->drawAt(at);
	}
	
	/* Main Lopp with GameManager */
	while (true) {
		long long mcr = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
		if(!(mcr % gameManager->getPlayer()->getTimeDelay())) gameManager->handleKeyboardInput();
		if(!(mcr % timeDelay::CANNON_SLOW)) gameManager->shootCannon(timeDelay::CANNON_SLOW);
		if(!(mcr % timeDelay::CANNON_FAST)) gameManager->shootCannon(timeDelay::CANNON_FAST);
		if (!(mcr % timeDelay::MOVABLE_OBJECT)) {
			gameManager->moveObjects();
			
		}	
	}	
}