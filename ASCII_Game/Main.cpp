#include <iostream>
#include <thread>   
#include "GameManagement.h"
#include "Cannon.h"
using namespace std; 

void play(GameManagement* gameManager) {
	

	while (true) {
		/*vector<string> board = gameManager->getBoard()->getBoardASCII();

		for (string line : board) {
			for (char litera : line) {
				cout << litera;
			}
			cout << '\n';
		}*/
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
	gameManager->putPlayer();
	gameManager->putCannons(); // put on ascii board
	gameManager->drawCannons(); // draw cannons, ats etc.
	
	
	//thread shootCannonSF{gameManager->shootCannonSlow};
	auto shootCannonSlow = std::thread(&GameManagement::shootCannonSlow, gameManager);
	auto shootCannonFast = std::thread(&GameManagement::shootCannonFast, gameManager);
	auto movePlayer = std::thread(&GameManagement::movePlayer, gameManager);
	auto playing = std::thread(play, gameManager);

	shootCannonSlow.join();
	shootCannonFast.join();
	movePlayer.join();
	playing.join();
	
}