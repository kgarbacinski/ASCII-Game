#include "Cannon.h"

Cannon::Cannon(int _xPos, int _yPos, int _shootDelay) : Object{ _xPos, _yPos, '|', '-' }, shootDelay{ _shootDelay }
{
}

void Cannon::drawObject(bool isVer)
{
	this->gotoxy(this->xPos, this->yPos);
	if (isVer) cout << this->reprVer;
	else cout << this->reprHor;
}
