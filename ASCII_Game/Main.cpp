#include <iostream>	
#include "GameManagement.h"
#include "Cannon.h"
using namespace std; 


int main() {
	GameManagement* gameManager = GameManagement::getInstance();

	gameManager->drawBoard();
	gameManager->putObjects(); // put on ascii board
	gameManager->drawObjects(); // draw cannons, ats etc.
	
	while (true) {
		gameManager->drawPlayer();
		gameManager->movePlayer();
	}
	
}