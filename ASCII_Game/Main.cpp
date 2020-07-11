#include <iostream>	
#include "Board.h"
using namespace std; 


int main() {
	// Create board
	Board* board = Board::getInstance();

	vector<string> boardVec;
	boardVec = board->getBoard();

	for (auto line : boardVec) {
		cout << line << endl;
	}

	
}