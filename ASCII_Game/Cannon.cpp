#include "Cannon.h"

Cannon::Cannon(int _xPos, int _yPos, int _shootDelay, bool _isVer) : Object{ _xPos, _yPos, '|', '-' }, shootDelay{ _shootDelay }, 
isVer{_isVer}
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

char Cannon::getReprBullet()
{
	return this->reprBullet;
}
