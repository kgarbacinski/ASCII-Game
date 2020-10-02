#include "Player.hpp"

Player::Player()
{
}

int Player::getStartxPos() const
{
	return this->startxPos;
}

int Player::getStartyPos() const
{
	return this->startyPos;
}

int Player::getTimeDelay() const
{
	return this->timeDelay;
}

int Player::getxPos() const
{
	return this->xPos;
}

int Player::getyPos() const
{
	return this->yPos;
}

int Player::getHealth() const
{
	return this->health;
}

int Player::getXCheckpoint() const
{
	return this->xCheckpoint;
}

int Player::getYCheckpoint() const
{
	return this->yCheckpoint;
}

void Player::setCheckpoint(int xPos, int yPos)
{
	this->xCheckpoint = xPos;
	this->yCheckpoint = yPos;
}

void Player::setxPos(int _xPos)
{
	this->xPos = _xPos; 
}

void Player::setyPos(int _yPos)
{
	this->yPos = _yPos;
}

void Player::setHealth(int _health)
{
	this->health = _health; 

}
