#include "Cannon.h"

Cannon::Cannon(const int& _xPos, const int& _yPos, const int& _timeDelay,const bool& _isVer,const char& _shootDir) : Object{ _xPos, _yPos, '|', '-', _timeDelay, _isVer }, shootDir{_shootDir}
{
}

void Cannon::drawBullet(const int& xPos, const int& yPos)
{
	this->gotoxy(xPos, yPos);

}

char Cannon::getReprBullet()
{
	return this->reprBullet;
}


char Cannon::getShootDir()
{
	return this->shootDir;
}
