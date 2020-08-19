#include "Cannon.h"

Cannon::Cannon(const int& _xPos, const int& _yPos, const int& _timeDelay, const bool& _isVer, const char& _shootDir) : ShootableObject{_shootDir, _xPos, _yPos, _timeDelay, '|', '-', _isVer}
{	
}

Cannon::~Cannon()
{
}

