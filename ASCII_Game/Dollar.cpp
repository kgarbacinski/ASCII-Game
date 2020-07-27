#include "Dollar.h"

Dollar::Dollar(const int& _xPos, const int& _yPos, const int& _xDir,const  char& _repr) : Object{ _xPos, _yPos, _repr, _repr }, xDir{_xDir}
{

}

const int& Dollar::getXDir() const 
{
	return this->xDir;
}

void Dollar::setXDir(const int& _xDir)
{
	this->xDir = _xDir;
}
