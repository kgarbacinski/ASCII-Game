#include "Board.h"
Board::Board() {
	this->readBoardASCII();
}

void Board::readBoardASCII()
{
	ifstream file("board.txt"); // create handler to file
	
	try {
		if (!file) throw "Error opening file!";
	}
	catch (const char* err) {
		cerr << err << '\n';
	}

	string line;
	while (getline(file, line)) {
		this->boardASCII.push_back(line);
	}

	file.close();

}

vector<string> Board::getBoardASCII()
{
	return this->boardASCII;
}

void Board::modifyBoardASCII(int x, int y, char newElement)
{
	this->boardASCII.at(y).at(x) = newElement;
}
