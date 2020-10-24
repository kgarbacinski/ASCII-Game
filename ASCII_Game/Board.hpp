#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cerr;
using std::ifstream;
using std::exception;
using std::cout;
using std::getline;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#pragma once
class Board{
private:
	vector<string> boardASCII; // contains whole board in ascii
	
public:
	Board();
	void readBoardASCII();

	vector<string> getBoardASCII();
	void modifyBoardASCII(int x, int y, char newElement);
};

