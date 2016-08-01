#pragma once
#include <SFML/Graphics.hpp>
class MainMenuInputHandler 
{
private:
	void ExitGame();
public:
	MainMenuInputHandler();
	~MainMenuInputHandler();
	void HandleInput(sf::Event &event);
};