#include "HighScore.h"
#include <iostream>
#include <fstream>
#include <string>

HighScore::HighScore()
{
}
extern unsigned int score;

HighScore::~HighScore()
{
}
//updates highscore list
void HighScore::Update(highscoreEntity &entity)
{
	std::list<highscoreEntity>::reverse_iterator rit;
	PrintHighscore();
	rit = highScore.rbegin();
	int i = 0;
	for (rit ; rit != highScore.rend(); ++rit)
	{
		std::cout << ++i <<":"<<"highscore name:" << rit->name << " " <<"highscore score: "<< rit->score <<"players score:" << score << std:: endl;
		if (rit->score >= score)
		{
			highScore.insert(rit.base(), entity);
			highScore.erase(--highScore.end());
			break;
		}
		else if (--rit.base() == highScore.begin())
		{
				printf("%i\n", rit->score);
				highScore.insert(--rit.base(), entity);
				highScore.erase(--highScore.end());
				break;
			}
	}
	PrintHighscore();
}
//reads highscore from file, updates it and writes it to file.
void HighScore::ReadUpdateWrite(highscoreEntity &entity)
{
	ReadHighscore();
	Update(entity);
	WriteHighscore();
	PrintHighscore();
}
//this method reads highscore from file, in case when file doesn't exists or is empty, fills highscore with xxxs and 0s values and writes it to file.
void HighScore::ReadHighscore()
{
	std::ifstream stream("HighScore.dat");//,std::ios::beg);

	if (!(stream.peek()==EOF) && stream)
	{
		std::string nameFromFile;
		int scoreFromFile;


		highscoreEntity single;
		while (stream)
		{	
			stream >> nameFromFile;
			stream >> scoreFromFile;
			if (!stream)break;
			single.name = nameFromFile;
			single.score = scoreFromFile;
			this->highScore.push_back(single);
		}
		
	}
	else
	{
		stream.close();
		highscoreEntity entity{ "XXX",0 };
		for (int i = 0; i < 10; ++i)
		{	
			highScore.insert(highScore.end(),entity);
		}
		WriteHighscore();
	}
}
//writes highscore to file
void HighScore::WriteHighscore()
{
	std::ofstream outputstream("HighScore.dat");
	std::list<highscoreEntity>::iterator it;
	for (it = highScore.begin(); it != highScore.end(); ++it)
	{
		outputstream << it->name << " " << it->score<< std::endl;;
	}
}
//print highscore to console
void HighScore::PrintHighscore()
{
	std::list<highscoreEntity>::iterator it;
	int i = 1;
	for (it = highScore.begin(); it != highScore.end(); ++it)
	{
		printf_s("%i: %s %i\n", i, it->name.c_str(),it->score);
		++i;
	}

}
//this method returns iterator pointing at beginning of highscore
std::list<highscoreEntity>::iterator HighScore::getHighScore() 
{
	return this->highScore.begin();
}
//this method returns iterator pointing at end of highscore
std::list<highscoreEntity>::iterator HighScore::getEndOfHighScore()
{
	return this->highScore.end();
}