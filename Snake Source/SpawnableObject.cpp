#include "SpawnableObject.h"
#include <random>
#include "Snake.h"

extern Snake snake;

SpawnableObject::SpawnableObject()
{
}

SpawnableObject::~SpawnableObject()
{
}

float SpawnableObject::getRandomNumber(int min, int max)
{
	std::random_device device;
	std::mt19937 MT_RandomNumberGenrator(device());
	double fraction = 1 / (double)(RAND_MAX) + 1.0;
	return MT_RandomNumberGenrator()%(max-min+1)+min;
	 
}