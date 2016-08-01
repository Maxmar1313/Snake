#pragma once
#include "MainMenuInputHandler.h"
//#include "SnakeInputHandler.h"
//#include "Snake.h"
#include  <Windows.h>
#include <time.h>
#include "Structures.h"
#include "InGame.h"
#include "EndGame.h"


using namespace sf;


class Game
{
	private:
		void setText(Text &text, Font &font, String textString, Color color, unsigned int size,Vector2f position);
		void showOptions(sf::RenderWindow &window, Font &font, unsigned int currentOption = 0);

	public:

	//void Render(Snake &snake);
	Game();
	~Game();

	void ShowMainMenu();
	void StartGame();
	void ShowEndGameScreen();
	void ShowHighScore();
	void ExitGame();
};

