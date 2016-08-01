#include "BluePowerUp.h"

extern bool isPowerUpAlreadySpawned;
extern Snake* snake;
extern int gameSpeed;
extern time_t previous;
extern bool isSnakeSlowedDown;
BluePowerUp::BluePowerUp(sf::Vector2f position)
{
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Blue);
	shape.setRadius(this->radius);

}


BluePowerUp::~BluePowerUp()
{
}
void BluePowerUp::onCollision()
{
	isPowerUpAlreadySpawned = false;
	isSnakeSlowedDown = true;
	for (int i = 1; i < snake->snake.size(); ++i)
	{
		snake->snake.at(i)->snakeSegment.setFillColor(sf::Color::Blue);
		snake->setColor(sf::Color::Blue);
	}
	gameSpeed = 150;
	previous = clock();
}
void BluePowerUp::revertBonus()
{
	isSnakeSlowedDown = false;
	for (int i = 1; i < snake->snake.size(); ++i)
	{
		snake->snake.at(i)->snakeSegment.setFillColor(sf::Color::White);
		snake->setColor(sf::Color::White);
	}
	gameSpeed = 100;
}

