#include "Cannon.h"

Cannon::Cannon(int _xPos, int _yPos, int _shootDelay, bool _isVer, char _shootDir) : Object{ _xPos, _yPos, '|', '-', _isVer }, shootDelay{ _shootDelay }, shootDir{_shootDir}
{
}

void Cannon::drawBullet(int xPos, int yPos)
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
