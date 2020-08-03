#include "Percent.h"

Percent::Percent(const int& _xPos, const int& _yPos, const int& _xStart, const int& _xEnd, const int& _yStart, const int& _yEnd) : 
	MovableObject{ 'L', _xPos, _yPos, '%', '%', true }, xStart{ _xStart }, xEnd{ _xEnd }, yStart{ _yStart }, yEnd{_yEnd} {

}

void Percent::moveObject()
{
	int dirs[2] = { 1, -1 };
	
	while (true) {
		int dirValue = dirs[rand() % 2]; // randomize x or y
		int xDir, yDir;
		if (dirValue == 1) {
			xDir = dirs[rand() % 2]; 
			yDir = 0;
		}
		else if (dirValue == -1) {
			yDir = dirs[rand() % 2];
			xDir = 0;
		}
		// Check if inside box
		int xNew = this->xPos + xDir, yNew = this->yPos + yDir;
		if (xNew < this->xEnd && xNew > this->xStart &&
			yNew > this->yStart && yNew < this->yEnd) {

			this->xPos += xDir;
			this->yPos += yDir;
			break;
		}
	}

	
}
