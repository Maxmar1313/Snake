#pragma once
#include <string>
#include <SFML/Window/Event.hpp>

class EndGameInputHandler
{
public:
	EndGameInputHandler();
	~EndGameInputHandler();
	void HandleInput(sf::Event &myEvent, std::pair<unsigned char, unsigned char> &currentLetter, std::string &playerNameString,unsigned char &numberOfProvidedLetters);
};

