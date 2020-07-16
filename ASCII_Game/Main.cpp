#include <iostream>
#include <thread>   
#include "GameManagement.h"
#include "Cannon.h"
using namespace std; 

void play(GameManagement* gameManager) {
	

	while (true) {
	}
}

int main() {
	GameManagement* gameManager = GameManagement::getInstance();

	// put first bullets on the board
	for (auto cannon : gameManager->getCannons()) {
		if(cannon->getShootDir() == 'D') gameManager->initBullet(cannon, 0, 1);
		if(cannon->getShootDir() == 'U') gameManager->initBullet(cannon, 0, -1);
		if(cannon->getShootDir() == 'R') gameManager->initBullet(cannon, 1, 0);
		if(cannon->getShootDir() == 'L') gameManager->initBullet(cannon, -1, 0);

	}

	gameManager->drawBoard();
	gameManager->drawPlayer();
	gameManager->putObjects(); // put on ascii board
	gameManager->drawObjects(); // draw cannons, ats etc.
	
	
	//thread shootCannonSF{gameManager->shootCannonSlow};
	auto f1 = std::thread(&GameManagement::shootCannonSlow, gameManager);
	auto f2 = std::thread(&GameManagement::movePlayer, gameManager);
	auto f3 = std::thread(play, gameManager);

	f1.join();
	f2.join();
	f3.join();
	
}