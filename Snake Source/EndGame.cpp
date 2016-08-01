#include "EndGame.h"
#include <list>
#include <Windows.h>
#include "EndGameInputHandler.h"
#include "Structures.h"

using namespace sf;

extern GameStatus gameStatus;
extern unsigned int score;
extern sf::RenderWindow window;
extern sf::Font font;


void setText(Text &text, Font &font, String textString, Color color, unsigned int size, Vector2f position);

// this method starts end game screen
void EndGame::startEndGameScreen()
{
	Event event;
	Text text;
	Text enterName;
	Text playerName;
	Text alphabet[2][13];
	EndGameInputHandler inputHandler;
	unsigned char numberOfprovidedLetters = 0;
	sf::RectangleShape marker;
	marker.setFillColor(sf::Color::White);
	marker.setSize({ 13,17 });

	if (!font.loadFromFile("arial.ttf"))
	{
		MessageBox(NULL, L"ERROR:Could Not Load Font", NULL, NULL);
	}

	do
	{
		if (gameStatus != GameStatus::ENDGAME_SCREEN)
			break;

		window.clear(sf::Color::Black);
	
	
		marker.setPosition(260.0f + 20*currentLetter.second, 302.0f + 20 * currentLetter.first);
		window.draw(marker);
		char letter;
		letter = 'A';
		char x = 0;
		char y = 0;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				if (currentLetter.first ==i && currentLetter.second == j)
				{
					setText(alphabet[i][j], font, letter, sf::Color::Black, 15, { 260.0f + 20 * x,300.0f + 20 * y });
				}
				else
				{
					setText(alphabet[i][j], font, letter, sf::Color::White, 15, { 260.0f + 20 * x,300.0f + 20 * y });
				}
				letter += 1;
				++x;
				if (12 == j )
				{
					x = 0;
					++y;
				}
				window.draw(alphabet[i][j]);
			}
		}

		std::string scoreText = "You have ended the game with score: " + std::to_string(score);
		setText(text, font, scoreText, sf::Color::Red, 20, { 220,150 });
		setText(enterName, font, "Please Enter Your Name", sf::Color::White, 20, { 280,180 });
		setText(playerName, font, playerNameString, sf::Color::White, 20, { 360,220 });

		//printf("code:%i\n", event.key.code);
		//printf("x: %i , y:%i\n", currentLetter.first, currentLetter.second);
		inputHandler.HandleInput(event,currentLetter,playerNameString,numberOfprovidedLetters);
		
		//render
		window.draw(text);
		window.draw(enterName);
		window.draw(playerName);
		window.display();

	} while (window.waitEvent(event));

}

EndGame::EndGame()
{
}

EndGame::~EndGame()
{
}
void setText(Text &text, Font &font, String textString, Color color, unsigned int size, Vector2f position)
{
	text.setFont(font);
	text.setString(textString);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setPosition(position);
}