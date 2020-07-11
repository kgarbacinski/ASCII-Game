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
	static Board* instance;
	Board();
public:
	static Board* getInstance() {
		if (instance == nullptr) {
			instance = new Board();
		}
		return instance;
	}

	vector<string> getBoard();
};

