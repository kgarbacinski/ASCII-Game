#include "WindowHandler.hpp"

#pragma once
class Menu : public WindowHandler
{
private:
	const int noOptions{ 2 };
	int currOption{ 0 }; // init with start pos
	bool isMenuRunning{ true };
	int windowWidth;
	int windowHeight;
	int cursorXPos;
	int cursorYPos;

	static Menu* instance;
	Menu();
	~Menu();
public:
	static Menu* getInstance();
	void drawMenu();
	void waitForInput();
	void drawCursor();
	void clearCursor();
	void moveCursor(int xMove, int yMove);
	void checkConfirmation();
};

