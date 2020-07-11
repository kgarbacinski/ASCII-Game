#pragma once
class Player
{
private:
	int yPos{36}, xPos{2};
	int health{ 100 };
public:
	Player();

	const int& getxPos() const;
	const int& getyPos() const;
	const int& getHealth() const;

	void setxPos(const int& _xPos);
	void setyPos(const int& _yPos);
	void setHealth(const int& _health);

};

