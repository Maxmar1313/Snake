#pragma once
#include "PowerUp.h"
class GreenPowerUp :
	public PowerUp
{
public:
	GreenPowerUp(sf::Vector2f position);
	~GreenPowerUp();
	void virtual onCollision();

};

