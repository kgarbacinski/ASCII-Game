#pragma once
class Player
{
private:
	const int startxPos{ 56 }; // 2
	const int startyPos{ 32 }; // 36
	const int timeDelay{ 100000 };

	int xPos{startxPos}, yPos{startyPos};
	int health{ 100 };
public:
	Player();

	const int& getStartxPos() const;
	const int& getStartyPos() const;
	const int& getTimeDelay() const;
	const int& getxPos() const;
	const int& getyPos() const;
	const int& getHealth() const;

	void setxPos(const int& _xPos);
	void setyPos(const int& _yPos);
	void setHealth(const int& _health);

};

