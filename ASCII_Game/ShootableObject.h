#include "Object.h"

#pragma once
class ShootableObject : public Object
{
private:
	const char reprBullet{'o'};
	char shootDir;
	int shootDelay;
public:
	ShootableObject(char _shootDir, int _xPos, int _yPos, int _shootDelay, char _reprVer, char _reprHor, bool _isVer) : Object{ _xPos, _yPos, _reprVer, _reprHor, _isVer }, shootDelay{_shootDelay}, shootDir{ _shootDir } {}

	void drawBullet() { cout << this->reprBullet;  }
	const char& getReprBullet() { return this->reprBullet; }
	const char& getShootDir() { return this->shootDir;  }

	const int& getShootDelay() { return this->shootDelay;  }
};

