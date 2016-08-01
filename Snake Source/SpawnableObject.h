#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

//Abstract class for spawnable objects such as: PowerUps, Apples
class SpawnableObject
{
private:
	

public:
	unsigned char radius;
	float static SpawnableObject::getRandomNumber(int min, int max);
	sf::CircleShape shape;
	SpawnableObject();
	virtual ~SpawnableObject();
	void virtual onCollision()=0;

//protected:
	//templeted function to spawn Spawnable objects
	template <typename T>
	T* spawnObject(Snake &snake)
	{
		{
			sf::Vector2f position = { getRandomNumber(0,780),getRandomNumber(0,580) };
			while (true)
			{
				for (int i = 0; i < snake.snake.size(); ++i)
				{
					if ( position == snake.snake.at(i)->snakeSegment.getPosition())
					{
						position = { getRandomNumber(0,780), getRandomNumber(0,580) };
						i = 0;
					}
				}
				break;
			}
			return new T(position);
		}
	}
	
};

