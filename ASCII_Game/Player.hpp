#pragma once
class Player
{
private:
	const int startxPos{ 2 }; // 2
	const int startyPos{ 36 }; // 36
	const int timeDelay{ 100000 };

	int xCheckpoint{ 2 }, yCheckpoint{ 36 };
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
	const int& getXCheckpoint() const;
	const int& getYCheckpoint() const;

	void setCheckpoint(const int& xPos, const int& yPos);
	void setxPos(const int& _xPos);
	void setyPos(const int& _yPos);
	void setHealth(const int& _health);

};

