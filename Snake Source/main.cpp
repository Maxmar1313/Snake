#include <SFML/Graphics.hpp>
#include "Game.h"

extern GameStatus gameStatus;

sf::RenderWindow window(sf::VideoMode(800, 600), "Snake", sf::Style::Titlebar | sf::Style::Close);
int main()
{
	Game game;
	while (window.isOpen()) 
	{
		switch (gameStatus)
		{
			case GameStatus::MAIN_MENU:
			{
				game.ShowMainMenu();
				break;
			}
			case GameStatus::IN_GAME:
			{
				game.StartGame();
				break;
			}
			case GameStatus::ENDGAME_SCREEN:
			{
				game.ShowEndGameScreen();
				break;
			}
			case GameStatus::HIGH_SCORE:
			{
				game.ShowHighScore();
				break;
			}
			case GameStatus::EXIT_GAME:
			{	
				game.ExitGame();
				break;
			}
		}
	}
	return 0;
}