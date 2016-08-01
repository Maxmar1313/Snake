#pragma once
#include "PowerUp.h"
class YellowPowerUp :
	public PowerUp
{
public:
	YellowPowerUp(sf::Vector2f position);
	~YellowPowerUp();
	void virtual onCollision();

};

