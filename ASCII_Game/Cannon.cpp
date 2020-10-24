#include "Cannon.hpp"

Cannon::Cannon(int _xPos, int _yPos, int _timeDelay, bool _isVer, char _shootDir) : ShootableObject{_shootDir, _xPos, _yPos, _timeDelay, '|', '-', _isVer}
{	
}

Cannon::~Cannon()
{
}

