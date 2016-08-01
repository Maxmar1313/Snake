#include "EndGameInputHandler.h"
#include "Structures.h"
#include<iostream>
#include "HighScore.h"
extern GameStatus gameStatus;
extern unsigned int score;
EndGameInputHandler::EndGameInputHandler()
{
}


EndGameInputHandler::~EndGameInputHandler()
{
}
void EndGameInputHandler::HandleInput(sf::Event &myEvent,std::pair<unsigned char,unsigned char> &currentLetter, std::string &playerNameString,unsigned char &numberOfProvidedLetters)
{
	
	switch (myEvent.type)
	{
		case sf::Event::Closed:
		{
			break;
		}

		case sf::Event::KeyPressed:
		{	
			switch (myEvent.key.code)
			{
				case sf::Keyboard::Up:
				{	
					if (0 == currentLetter.first)
						currentLetter.first = 1;
					else
						currentLetter.first = 0;

					break;
				}

				case sf::Keyboard::Down:
				{	
					if (1 == currentLetter.first)
						currentLetter.first = 0;
					else
						currentLetter.first = 1;
					break;
				}

				case sf::Keyboard::Left:
				{	
					if (0 == currentLetter.second)
						currentLetter.second = 12;
					else
						currentLetter.second -= 1;
					break;
				}

				case sf::Keyboard::Right:
				{	
					if (12 == currentLetter.second)
						currentLetter.second = 0;
					else
						currentLetter.second += 1;
					break;
				}

				case sf::Keyboard::Return:
				{
					if (3 == numberOfProvidedLetters)
					{	
						highscoreEntity entity;
						entity.name = playerNameString;
						entity.score = score;
						HighScore highscore;
						highscore.ReadUpdateWrite(entity);
						gameStatus = GameStatus::MAIN_MENU;
						break;
					}
					char letter = 'A';
					letter += 13*(currentLetter.first) + (currentLetter.second);
					playerNameString[numberOfProvidedLetters] = letter;
					++numberOfProvidedLetters;
					break;
				}

				case sf::Keyboard::BackSpace:
				{
					if (0 == numberOfProvidedLetters)
						break;
					--numberOfProvidedLetters;
					playerNameString[numberOfProvidedLetters] = '_';
					break;
				}
				case sf::Keyboard::Space:
				{
				}
			}
			break;
		}
	}
}