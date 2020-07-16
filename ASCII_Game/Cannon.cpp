#include "Cannon.h"

Cannon::Cannon(int _xPos, int _yPos, int _shootDelay, bool _isVer, char _shootDir) : Object{ _xPos, _yPos, '|', '-' }, shootDelay{ _shootDelay }, 
isVer{ _isVer }, shootDir{_shootDir}
{
}

void Cannon::drawObject()
{
	this->gotoxy(this->xPos, this->yPos);
	if (this->isVer) cout << this->reprVer;
	else cout << this->reprHor;
}

void Cannon::drawBullet(int xPos, int yPos)
{
	this->gotoxy(xPos, yPos);
	cout << this->reprBullet;
}

int Cannon::getShootDelay()
{
	return this->shootDelay;
}

char Cannon::getReprBullet()
{
	return this->reprBullet;
}

bool Cannon::getIsVer()
{
	return this->isVer;
}

char Cannon::getShootDir()
{
	return this->shootDir;
}
