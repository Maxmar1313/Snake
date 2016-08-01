#pragma once
#include <SFML/Graphics.hpp>
#include <list>
enum class Direction :char
{	
	LEFT = -2,
	UP=-1,
	DOWN=1,
	RIGHT = 2,
};

static float size = 15;
static int i = 0; //this variable is only for debugging purpose

struct Segment
{
private:
	int i;
public:
	Direction movementDirection;
	sf::RectangleShape snakeSegment;
	Segment(sf::Vector2f position, Direction direction,sf::Color color)
	{
		i=++::i;
		movementDirection=direction;
		printf("segment number %i has been created\n",i);
		snakeSegment.setPosition(position);
		snakeSegment.setSize({ size , size });
		snakeSegment.setFillColor(color);
	}
	~Segment()
	{	
		printf("segment number %i has been destroyed\n",i);
		
	}
};

class Snake
{
	
public:
	friend class SnakeInputHandler;
	Snake();
	~Snake();
	void addSegment();
	void move();
	std::vector<Segment*> snake;
	void updateDirection();
	void Snake::setColor(sf::Color color);

private:
	sf::Color color = sf::Color::White;
	Segment *head;
	Segment *tail;
	double velocity;

};
