#include "Object.hpp"

#pragma once
class ShootableObject : public Object
{
private:
	char reprBullet{'o'};
	char shootDir;
	int shootDelay;
public:
	ShootableObject(char _shootDir, int _xPos, int _yPos, int _shootDelay, char _reprVer, char _reprHor, bool _isVer) : Object{ _xPos, _yPos, _reprVer, _reprHor, _isVer }, shootDelay{_shootDelay}, shootDir{ _shootDir } {}
	virtual ~ShootableObject() {}

	void drawBullet() { cout << this->reprBullet;  }
	char getReprBullet() { return this->reprBullet; }
	char getShootDir() { return this->shootDir;  }

	int getShootDelay() { return this->shootDelay;  }
};

