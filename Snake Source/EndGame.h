#pragma once
#include <SFML/Graphics.hpp>
class EndGame
{
public:
	EndGame();
	~EndGame();
	void startEndGameScreen();
private:
	std::string playerNameString = "___";
	std::pair<unsigned char, unsigned char> currentLetter = { 0,0 };

};

