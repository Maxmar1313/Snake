#include "Apple.h"
extern unsigned int score;
extern Snake* snake;
Apple::Apple(sf::Vector2f position)
{
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Red);
	radius = 10;
	shape.setRadius(radius);
	//min = position;
	//max.x = position.x + 2*radius;
	//max.y = position.y + 2 * radius;
}

Apple::~Apple()
{
}
void Apple::onCollision()
{	
	score+=10;
	snake->addSegment();
	//delete this;
	//increase score;
}

