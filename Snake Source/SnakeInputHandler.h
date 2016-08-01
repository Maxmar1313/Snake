#pragma once
#include "Snake.h"
class SnakeInputHandler
{
public:
	SnakeInputHandler();
	~SnakeInputHandler();
	void HandleInput(sf::Event &event,Snake &snake);
};

