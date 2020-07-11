#include "Player.h"

Player::Player()
{
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
