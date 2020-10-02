#pragma once
class Player
{
private:
	int startxPos{ 2 }; // 2
	int startyPos{ 36 }; // 36
	int timeDelay{ 100000 };

	int xCheckpoint{ 2 }, yCheckpoint{ 36 };
	int xPos{startxPos}, yPos{startyPos};
	int health{ 100 };
public:
	Player();

	int getStartxPos() const;
	int getStartyPos() const;
	int getTimeDelay() const;
	int getxPos() const;
	int getyPos() const;
	int getHealth() const;
	int getXCheckpoint() const;
	int getYCheckpoint() const;

	void setCheckpoint(int xPos, int yPos);
	void setxPos(int _xPos);
	void setyPos(int _yPos);
	void setHealth(int _health);

};

