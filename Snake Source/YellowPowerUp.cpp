#include "YellowPowerUp.h"


extern bool isPowerUpAlreadySpawned;
extern Snake* snake;
extern time_t previous;
YellowPowerUp::YellowPowerUp(sf::Vector2f position)
{
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Yellow);
	shape.setRadius(this->radius);
	printf("RADIUS: %f\n", this->radius);
}


YellowPowerUp::~YellowPowerUp()
{
}

void YellowPowerUp::onCollision() 
{	
	isPowerUpAlreadySpawned=false;
	previous = clock();

}
