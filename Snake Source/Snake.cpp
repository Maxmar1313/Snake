#include "Snake.h"


Snake::Snake() :velocity(15)
{	
	this->head = new Segment({ 405,300 }, Direction::RIGHT,sf::Color::Cyan);
	this->tail = this->head;
	snake.push_back(this->head);
	for (int i = 0; i < 2; ++i)
	{
		addSegment();
	}
}


Snake::~Snake()
{
	for (int i = 0; i < snake.size(); ++i)
	{
		delete snake.at(i);
	}
}

void Snake::setColor(sf::Color color)
{
	this->color = color;
}

void Snake::addSegment()
{
	sf::Vector2f position;
	Direction direction = this->tail->movementDirection;

	switch (direction)
	{
		case Direction::UP:
		{	
			position.x = this->tail->snakeSegment.getPosition().x;
			position.y= this->tail->snakeSegment.getPosition().y - size;
			break;
		}
		case Direction::DOWN:
		{
			position.y= this->tail->snakeSegment.getPosition().y + size;
			position.x = this->tail->snakeSegment.getPosition().x;
			break;
		}
		case Direction::RIGHT:
		{	
			position.x = this->tail->snakeSegment.getPosition().x - size;
			position.y = this->tail->snakeSegment.getPosition().y;
			break;
		}
		case Direction::LEFT:
		{	
			position.x = this->tail->snakeSegment.getPosition().x + size;
			position.y = this->tail->snakeSegment.getPosition().y;
			break;
		}
	}

	this->tail = new Segment(position,direction,this->color);
	snake.push_back(this->tail);
}


void Snake::updateDirection()
{
	for (int i = 1; i < snake.size(); ++i)
	{
		this->snake.at(i)->movementDirection = this->snake.at(i - 1)->movementDirection;
	}
}

void Snake::move()
{	
	for (int i = this->snake.size(); i > 1; --i)
	{
	
		sf::Vector2f nextPosition = this->snake.at(i - 2)->snakeSegment.getPosition();
		this->snake.at(i-1)->snakeSegment.setPosition(nextPosition);
	}

	sf::Vector2f newPosition = head->snakeSegment.getPosition();

	switch (this->head->movementDirection) 
	{
		case Direction::RIGHT:
		{	
			newPosition.x += 15;
			break;
		}
		case Direction::LEFT:
		{	
			newPosition.x -= 15;
			break;
		}
			
		case Direction::UP:
		{
			newPosition.y -= 15;
			break;
		}
			
		case Direction::DOWN:
		{
			newPosition.y += 15;
			break;
		}	
	}
	this->head->snakeSegment.setPosition(newPosition);
}