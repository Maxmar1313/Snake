#pragma once
#include <list>
#include "Structures.h"
class HighScore
{
public:
	HighScore();
	~HighScore();
	void ReadHighscore();
	void ReadUpdateWrite(highscoreEntity &entity);
	std::list<highscoreEntity>::iterator getHighScore();
	std::list<highscoreEntity>::iterator getEndOfHighScore();

private:
	std::list<highscoreEntity> highScore;
	void Update(highscoreEntity &entity);
	void PrintHighscore();
	void WriteHighscore();
};

