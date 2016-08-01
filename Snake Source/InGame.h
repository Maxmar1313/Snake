#pragma once
#include "SnakeInputHandler.h"
#include "Snake.h"
#include "Structures.h"
#include "Apple.h"
#include "BluePowerUp.h"
#include "GreenPowerUp.h"
#include "YellowPowerUp.h"

using namespace sf;

class InGame
{
//	friend void Apple::onCollision();
	//friend void SnakeInputHandler::HandleInput();
private:
	Text scoreText;
	void Render(Snake &snake);
	void drawsnake(Snake &snake);
	void update(Snake &snake);
	void setText(Text &text, Font &font, String textString, Color color, unsigned int size, Vector2f position);
	void InGame::detectCollision(SpawnableObject* &object, Snake &snake);
	void InGame::spawnPowerUp(Snake &snake);
	bool isColliding(SpawnableObject* object, Segment* snakesHead);
	bool InGame::snakeHitWall();
	bool InGame::snakeAteHimself();
	void InGame::isGameOver();

	SpawnableObject* apple = NULL;
	SpawnableObject* powerUp = NULL;
	const int HEAD = 0;
	

public:
	InGame();
	~InGame();
	void startGame();
};

