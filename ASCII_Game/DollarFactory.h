#include "MovableObjectFactory.h"

#pragma once
class DollarFactory : public MovableObjectFactory
{
public:
	MovableObject* createObject(const int& _xPos, const int& _yPos, const char& _moveDir) override;
};

