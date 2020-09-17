#include "Player.h"

Player::Player()
{
}

const int& Player::getStartxPos() const
{
	return this->startxPos;
}

const int& Player::getStartyPos() const
{
	return this->startyPos;
}

const int& Player::getTimeDelay() const
{
	return this->timeDelay;
}

const int& Player::getxPos() const
{
	return this->xPos;
}

const int& Player::getyPos() const
{
	return this->yPos;
}

const int& Player::getHealth() const
{
	return this->health;
}

const int& Player::getXCheckpoint() const
{
	return this->xCheckpoint;
}

const int& Player::getYCheckpoint() const
{
	return this->yCheckpoint;
}

void Player::setCheckpoint(const int& xPos, const int& yPos)
{
	this->xCheckpoint = xPos;
	this->yCheckpoint = yPos;
}

void Player::setxPos(const int& _xPos)
{
	this->xPos = _xPos; 
}

void Player::setyPos(const int& _yPos)
{
	this->yPos = _yPos;
}

void Player::setHealth(const int& _health)
{
	this->health = _health; 

}
