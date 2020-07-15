#include <iostream>
#include <thread>   
#include "GameManagement.h"
#include "Cannon.h"
using namespace std; 


int main() {
	GameManagement* gameManager = GameManagement::getInstance();

	gameManager->drawBoard();
	gameManager->drawPlayer();
	gameManager->putObjects(); // put on ascii board
	gameManager->drawObjects(); // draw cannons, ats etc.
	
	
	//thread shootCannonSF{gameManager->shootCannonSlow};
	auto f1 = std::thread(&GameManagement::shootCannonSlow, gameManager);
	f1.join();
	
}