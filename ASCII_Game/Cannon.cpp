#include "Cannon.h"

Cannon::Cannon(const int& _xPos, const int& _yPos, const int& _shootDelay,const bool& _isVer,const char& _shootDir) : Object{ _xPos, _yPos, '|', '-', _isVer }, shootDelay{ _shootDelay }, shootDir{_shootDir}
{
}

void Cannon::drawBullet(const int& xPos, const int& yPos)
{
	this->gotoxy(xPos, yPos);

}

int Cannon::getShootDelay()
{
	return this->shootDelay;
}

char Cannon::getReprBullet()
{
	return this->reprBullet;
}


char Cannon::getShootDir()
{
	return this->shootDir;
}
