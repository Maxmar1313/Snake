#pragma once

#include "SpawnableObject.h"
#include <SFML/Graphics.hpp>

class Apple :
	public SpawnableObject
{
private:
		
	//	sf::Vector2f min;
	//	sf::Vector2f max;
	
public:
	Apple(sf::Vector2f position);
	~Apple();
	void virtual onCollision();
	
};

