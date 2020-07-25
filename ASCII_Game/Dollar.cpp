#include "Dollar.h"

Dollar::Dollar(int _xPos, int _yPos, int _xDir, char _repr) : Object{ _xPos, _yPos, _repr, _repr }, xDir{_xDir}
{

}

int Dollar::getXDir()
{
	return this->xDir;
}

void Dollar::setXDir(int _xDir)
{
	this->xDir = _xDir;
}
