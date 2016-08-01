#include "MainMenuInputHandler.h"
#include "Game.h"

extern sf::RenderWindow window;
extern int currentOption;
extern GameStatus gameStatus;

MainMenuInputHandler::MainMenuInputHandler()
{
}

MainMenuInputHandler::~MainMenuInputHandler()
{
}

void MainMenuInputHandler::ExitGame()
{
	gameStatus = GameStatus::EXIT_GAME;
}

void MainMenuInputHandler:: HandleInput(sf::Event &event) 
{
	switch(event.type)
	{
		case sf::Event::KeyPressed:
		{
			printf("code:%i\n", event.key.code);
			switch (event.key.code) 
			{
				case sf::Keyboard::Up:
				{	if (1 == currentOption)
					currentOption = 3;
				else
					--currentOption;
					break;
				}
				case sf::Keyboard::Down:
				{
					if (3 == currentOption)
						currentOption = 1;
					else
					++currentOption;
					break;
				}
				case sf::Keyboard::Return:
				{	
					switch (currentOption)
					{
						case 1:
						{	
							gameStatus = GameStatus::IN_GAME;
							break;
						}
						case 2:
						{	
							gameStatus = GameStatus::HIGH_SCORE;
							break;
						}
						case 3:
						{
							ExitGame();
							break;
						}
					}
					break;
				}
				case sf::Keyboard::Escape:
				{
					ExitGame();
					break;
				}
				case sf::Event::Closed:
				{
					ExitGame();
					break;
				}
			}
		}
	}
}