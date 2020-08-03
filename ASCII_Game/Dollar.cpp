#include "Dollar.h"

Dollar::Dollar(const int& _xPos, const int& _yPos, const char& _moveDir) : MovableObject{ _moveDir, _xPos, _yPos, '$', '$', true }
{

}

void Dollar::moveObject()
{
	this->xPos = xPos + this->xDir;
}


