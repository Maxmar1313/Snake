#include "InGame.h"
#include <iostream>

extern RenderWindow window;
extern GameStatus gameStatus;
extern Font font;
extern unsigned int score;

bool isPowerUpAlreadySpawned;
bool isSnakeSlowedDown;
int gameSpeed;
Snake* snake;
time_t previous;

InGame::InGame()
{
}

InGame::~InGame()
{
}
//detects collision with AABB method
void InGame::detectCollision(SpawnableObject*& object,Snake &snake)
{

	Vector2f position1 = snake.snake.at(HEAD)->snakeSegment.getPosition();
	Vector2f position2 = object->shape.getPosition();
	bool b = isColliding(object, snake.snake.at(0));

		if( b == true)
		{	
			object->onCollision();
			delete object;
			object = NULL;
		}
}
//detects collision with AABB method
bool InGame::isColliding(SpawnableObject* object, Segment *snakesHead)
{
	Vector2f objectMin, objectMax, headMin, headMax;

	objectMin = object->shape.getPosition();
	objectMax.x = object->shape.getPosition().x + 2* object->radius;
	objectMax.y = object->shape.getPosition().y + 2* object->radius;

	headMin = snakesHead->snakeSegment.getPosition();
	headMax.x = snakesHead->snakeSegment.getPosition().x + snakesHead->snakeSegment.getSize().x;
	headMax.y = snakesHead->snakeSegment.getPosition().y + snakesHead->snakeSegment.getSize().y;

	float d1x =  headMin.x - objectMax.x;
	float d1y =  headMin.y- objectMax.y;
	float d2x =  objectMin.x - headMax.x;
	float d2y =  objectMin.y - headMax.y;
	if (d1x > 0.0f || d1y > 0.0f)
	{

		return false;
	}

	if (d2x > 0.0f || d2y > 0.0f)
	{
		return false;
	}
	return true;
}
//updates with single frame
void InGame::update(Snake &snake)
{	
	
	spawnPowerUp(snake);
	detectCollision(apple,snake);
	if (isSnakeSlowedDown == true) 
	{
		time_t current = clock();
		static time_t cooldown = 5000;
		printf("elapsed::%i\n", current - previous);
		if (current - previous > cooldown)
		{
			BluePowerUp::revertBonus();
		}
		
	}
	if (apple == NULL)
	{	
		apple = apple->spawnObject<Apple>(snake);
	}

	if (powerUp != NULL)
	{
		detectCollision(powerUp, snake);
	}

	snake.move();
	isGameOver();
}
//sets sf::text object, main purpose is to decrease amount of code
void InGame::setText(Text &text, Font &font, String textString, Color color, unsigned int size, Vector2f position)
{
	text.setFont(font);
	text.setString(textString);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setPosition(position);
}
//this method draws snake
void  InGame::drawsnake(Snake &snake)
{	
	for (int i = 0; i < snake.snake.size(); ++i)
	{
		window.draw(snake.snake.at(i)->snakeSegment);
	}
}
//this method spawns power up
void InGame::spawnPowerUp(Snake &snake)
{	
	time_t cooldown = 10000;
	time_t current = clock();
	time_t elapsed = current - previous;
	printf("elapse: %d\n", elapsed);
	//cheks if powerUp is already spawned(only one powerUp at time is expected)
	if (!isPowerUpAlreadySpawned)
	{
		//if powerUp is not spawned, check if cooldown passed, if so, randomly spawn one of 3 types of powerUp
		if (cooldown - elapsed < 0)
		{	
			int powerUpType = SpawnableObject::getRandomNumber(0, 2);
			switch (powerUpType)
			{
			case 0:
			{
				powerUp = powerUp->spawnObject<GreenPowerUp>(snake);

				break;
			}
			case 1:
			{
				powerUp = powerUp->spawnObject<BluePowerUp>(snake);

				break;
			}
			case 2:
			{
				powerUp = powerUp->spawnObject<YellowPowerUp>(snake);

				break;
			}
			}


			isPowerUpAlreadySpawned = true;
		}
	}
	//delete powerUp, after its lifetime has ended
	else if (elapsed > 20000)
	{
		delete powerUp;
		powerUp = NULL;
		isPowerUpAlreadySpawned = false;
		previous = clock();
	
	}
}
//renders game
void InGame::Render(Snake &snake)
{	
	drawsnake(snake);
	if (apple != NULL)
	{
		window.draw(apple->shape);
	};

	if (powerUp != NULL)
	{
		window.draw(powerUp->shape);
	}

	scoreText.setString(std::to_string(score));
	window.draw(scoreText);
	window.display();
}
//this method stars game
void  InGame::startGame()
{
	isPowerUpAlreadySpawned = false;
	isSnakeSlowedDown= false;
	Event event;
	//input handler for game, inputhandler controlls snake movement direction
	SnakeInputHandler *input = new SnakeInputHandler();
	snake = new Snake();
	gameSpeed = 100;
	previous = clock();
	score = 0;

	apple = new Apple({Apple::getRandomNumber(0,800),Apple::getRandomNumber(0,600)});

	setText(scoreText, font, std::to_string(score), Color::Red, 25, { 5,0 });

	clock_t previousTime = clock();
	clock_t lag = 0;
	//game loop
	while (gameStatus == GameStatus::IN_GAME)
	{	
		window.pollEvent(event);
		window.clear(Color::Black);

		snake->updateDirection();
		input->HandleInput(event,*snake);

		clock_t currentTime = clock();
		clock_t elapsed = currentTime - previousTime;

		lag += elapsed;
		previousTime = currentTime;

		while (lag > gameSpeed)
		{
			//printf("lag:%d , gamespeed %d\n", lag, gameSpeed);
			update(*snake);
			lag -= gameSpeed;
		}
		Render(*snake);
	};
	//after game is over, delete every dynamically allocated variables
	delete input;
	delete apple;
	delete snake;
	//check if powerUp has not been already deleted
	if (powerUp != nullptr)
	{
		delete powerUp;
	}

}
//this method checks if snake hit edge of sceen
bool InGame::snakeHitWall()
{	
	int x = snake->snake.at(HEAD)->snakeSegment.getPosition().x;
	int y = snake->snake.at(HEAD)->snakeSegment.getPosition().y;
	printf("x:%i , y:%i\n", x, y);
	if (x < 0 || y < 0 || x > 785 || y > 585) 

		return true;
	else
		return false;
}
//this method checks if snake hit himself( ate himself)
bool InGame::snakeAteHimself() 
{
	Vector2f headPosition = snake->snake.at(0)->snakeSegment.getPosition();
	for (int i =3; i < snake->snake.size(); ++i)
	{	
		Vector2f segmentPosition = snake->snake.at(i)->snakeSegment.getPosition();
		if (segmentPosition == headPosition)
			return true;
	}
	return false;
}
//this method checks and resolves end of game.
void InGame::isGameOver()
{
	if (snakeHitWall() || snakeAteHimself())
	{
		gameStatus = GameStatus::ENDGAME_SCREEN;
	}
}