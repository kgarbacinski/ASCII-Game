#include <iostream>	
#include "GameManagement.h"
using namespace std; 


int main() {
	GameManagement* gameManager = GameManagement::getInstance();

	gameManager->drawBoard();
	while (true) {
		gameManager->drawPlayer();
		gameManager->movePlayer();
	}
	
}