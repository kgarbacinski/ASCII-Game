#include "Board.h"
Board* Board::instance = nullptr;

Board::Board() {}

vector<string> Board::getBoard()
{
	ifstream file("board.txt"); // create handler to file
	vector <string> board;
	
	try {
		if (!file) throw "Error opening file!";
	}
	catch (const char* err) {
		cerr << err << '\n';
		
	}

	string line;
	while (getline(file, line)) {
		board.push_back(line);
	}

	file.close();
	
	return board;
}
