#pragma once
class Player
{
private:
	const int startxPos = 2;
	const int startyPos = 36;

	int xPos{startxPos}, yPos{startyPos};
	int health{ 100 };
public:
	Player();

	const int& getStartxPos();
	const int& getStartyPos();
	const int& getxPos() const;
	const int& getyPos() const;
	const int& getHealth() const;

	void setxPos(const int& _xPos);
	void setyPos(const int& _yPos);
	void setHealth(const int& _health);

};

