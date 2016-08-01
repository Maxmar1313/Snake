#include "GreenPowerUp.h"

extern Snake* snake;
extern bool isPowerUpAlreadySpawned;
extern time_t previous;
extern unsigned int score;
GreenPowerUp::GreenPowerUp(sf::Vector2f position)
{
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Green);
	shape.setRadius(this->radius);

}


GreenPowerUp::~GreenPowerUp()
{
}
void GreenPowerUp::onCollision()
{
	score += 30;
	isPowerUpAlreadySpawned = false;
	previous = clock();

}
