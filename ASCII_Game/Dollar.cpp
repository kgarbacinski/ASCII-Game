#include "Dollar.hpp"

Dollar::Dollar(int _xPos, int _yPos, char _moveDir) : MovableObject{ _moveDir, _xPos, _yPos, '$', '$', true }
{

}

Dollar::~Dollar()
{
}

void Dollar::moveObject()
{
	this->xPos = xPos + this->xDir;
}


