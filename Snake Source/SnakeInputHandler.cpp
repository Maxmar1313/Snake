#include "SnakeInputHandler.h"
#include "Game.h"
extern sf::RenderWindow window;

extern GameStatus gameStatus;

SnakeInputHandler::SnakeInputHandler()
{
}


SnakeInputHandler::~SnakeInputHandler()
{
}
void SnakeInputHandler::HandleInput(sf::Event &event,Snake &snake)
{
	switch (event.type)
	{
		case sf::Event::Closed:
		{
			gameStatus = GameStatus::EXIT_GAME;
		}
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
				case sf::Keyboard::Up:
				{	
					if(snake.head->movementDirection!=Direction::DOWN)
					snake.head->movementDirection = Direction::UP;
					break;
				}
				case sf::Keyboard::Down:
				{	
					if (snake.head->movementDirection != Direction::UP)
					snake.head->movementDirection = Direction::DOWN;
					break;
				}
				case sf::Keyboard::Right:
				{	
					if (snake.head->movementDirection != Direction::LEFT)
					snake.head->movementDirection = Direction::RIGHT;
					break;
				}
				case sf::Keyboard::Left:
				{	
					if (snake.head->movementDirection != Direction::RIGHT)
					snake.head->movementDirection = Direction::LEFT;
					break;
				}
				case sf::Keyboard::P:
				{
					//PauseGame = true;
				}
			}
		
	}
};