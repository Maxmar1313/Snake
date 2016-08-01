#pragma once
#include "PowerUp.h"
class BluePowerUp :
	public PowerUp
{
	
public:
	BluePowerUp(sf::Vector2f position);
	~BluePowerUp();
	void virtual onCollision();
	static void BluePowerUp::revertBonus();
};

