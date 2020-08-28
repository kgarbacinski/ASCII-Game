#include <iostream>
#include <thread>   
#include "GameManagement.h"
#include "Cannon.h"
#include "Menu.h"
using namespace std; 

int main() {
	srand(time(NULL));
<<<<<<< HEAD
=======

<<<<<<< HEAD
>>>>>>> b77d54b39027634d29921ea3bd162fbefe868007
=======
	Menu* menu = Menu::getInstance();

	menu->drawMenu();

>>>>>>> f3d3281e3b741bc6af659509302e56ee7ba79342
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
	gameManager->putMovObjects();
	gameManager->drawMovObjects();

	for (auto at : gameManager->getAts()) {
		gameManager->putAt(at);
		gameManager->drawAt(at);
	}
	
	/* Main Lopp with GameManager */
	while (true) {
		long long mcr = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
		if(!(mcr % gameManager->getPlayer()->getTimeDelay())) gameManager->movePlayer();
		if(!(mcr % timeDelay::CANNON_SLOW)) gameManager->shootCannon(timeDelay::CANNON_SLOW);
		if(!(mcr % timeDelay::CANNON_FAST)) gameManager->shootCannon(timeDelay::CANNON_FAST);
		if (!(mcr % timeDelay::MOVABLE_OBJECT)) {
			gameManager->moveObjects();
			
		}

		
	}
	
	////thread shootCannonSF{gameManager->shootCannonSlow};
	//auto shootCannonSlow = std::thread(&GameManagement::shootCannonSlow, gameManager);
	//auto shootCannonFast = std::thread(&GameManagement::shootCannonFast, gameManager);
	//auto movePlayer = std::thread(&GameManagement::movePlayer, gameManager);
	//auto moveDollar = std::thread(&GameManagement::moveDollars, gameManager);
	//auto playing = std::thread(play, gameManager);

	//shootCannonSlow.join();
	//shootCannonFast.join();
	//movePlayer.join();
	//moveDollar.join();
	//playing.join();
	
}