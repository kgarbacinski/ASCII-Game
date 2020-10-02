#include "MovableObject.hpp"

#pragma once
class Dollar : public MovableObject
{
public:
	Dollar(int _xPos, int _yPos, char _moveDir);
	~Dollar();
	void moveObject() override;

};

