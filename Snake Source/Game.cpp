#include "Game.h"
#include "HighScore.h"
#include <iostream>
extern sf::RenderWindow window;
Font font;
int currentOption = 0;
GameStatus gameStatus = GameStatus::MAIN_MENU;
unsigned int score;

Game::Game()
{

}

Game::~Game()
{

}
	//this method is used to setText for sf::Text objects, the main purpose is to decrease amount of code
void Game::setText(Text &text, Font &font, String textString, Color color, unsigned int size, Vector2f position)
{
	text.setFont(font);
	text.setString(textString);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setPosition(position);
}

//this method displays main menu options
void Game::showOptions(sf::RenderWindow &window,Font &font,unsigned int currentOption) 
{
	Color white = Color::White;
	Color black = Color::Black;
	unsigned char size = 30;
	float xPosition =320.f;
	float yPosition = 200.f;
	Text NewGameText;
	Text HighScoreText;
	Text ExitText;
	RectangleShape marker;
	
	marker.setFillColor(white);
	
	switch (currentOption) 
	{
		case 1: 
		{		
				marker.setSize({ 155,40 });
				marker.setPosition(xPosition -5 , yPosition);
				window.draw(marker);

				setText(NewGameText, font, "New Game", black, size, { xPosition,yPosition });			
				setText(HighScoreText, font, "High Score", white, size, { xPosition,yPosition + 30 });	
				setText(ExitText, font, "Exit Game", white, size, { xPosition,yPosition + 60 });
				break;
			}
		case 2:
			{	
				marker.setSize({ 155,40 });
				marker.setPosition(xPosition -5 , yPosition + 30);
				window.draw(marker);

				setText(NewGameText, font, "New Game", white, size, { xPosition,yPosition });
				setText(HighScoreText, font, "High Score", black, size, { xPosition,yPosition + 30 });
				setText(ExitText, font, "Exit Game", white, size, { xPosition,yPosition + 60 });
				break;
			}
		case 3:
			{	

				marker.setSize({ 155,40 });
				marker.setPosition(xPosition -5, yPosition + 60);
				window.draw(marker);

				setText(NewGameText, font, "New Game", white, size, { xPosition,yPosition });
				setText(HighScoreText, font, "High Score", white, size, { xPosition,yPosition + 30 });
				setText(ExitText, font, "Exit Game", black, size, { xPosition,yPosition + 60 });
				break;
			}
		default:
		{	setText(NewGameText, font, "New Game", white, size, { xPosition,yPosition });
			setText(HighScoreText, font, "High Score", white, size, { xPosition,yPosition + 30 });
			setText(ExitText, font, "Exit Game", white, size, { xPosition,yPosition + 60 });
			break;
		}
	}
	
	window.draw(NewGameText);
	window.draw(HighScoreText);
	window.draw(ExitText);
	window.display();

}

//this method displays main menu and handle user input.
void Game::ShowMainMenu()
{
	Event event;
	MainMenuInputHandler *input = new MainMenuInputHandler();
	if (!font.loadFromFile("arial.ttf"))
	{
		MessageBox(NULL, L"ERROR:Could Not Load Font", NULL, NULL);
	}

	
	do {
		if (gameStatus != GameStatus::MAIN_MENU)
			break;
		printf("GAME STATUS %i\n",gameStatus);
		window.clear(Color::Black);
		input->HandleInput(event);
		showOptions(window, font,currentOption);

	} 
		while (window.waitEvent(event));
	delete input;
}

//this method stats game
void Game::StartGame()
{
	InGame ingame;
	ingame.startGame();
}

void Game::ShowEndGameScreen()
{
	EndGame endgame;
	endgame.startEndGameScreen();
}
//this methods displays high score
void Game::ShowHighScore()
{
	HighScore highscore;
	sf::Text highScoreText[10];
	sf::Text header;
	//in case 
	highscore.ReadHighscore();
	std::list<highscoreEntity>::iterator it = highscore.getHighScore();
	int	i = 0;
	window.clear(sf::Color::Black);
	setText(header, font, "HIGHSCORE:", sf::Color::Red, 30, { 10,0 });
	window.draw(header);
	for (it; it != highscore.getEndOfHighScore(); ++it)
	{
		std::string entrytext;
		entrytext = std::to_string(i + 1) + ". " + it->name + " " + std::to_string(it->score) + "\n";
		//std::cout << entrytext << std::endl;
		setText(highScoreText[i], font, entrytext, sf::Color::White, 20, { 10, 0 + 40.0f * (i+1) });
		window.draw(highScoreText[i]);
		++i;
		
	}
	window.display();
	Event event;
	while (window.pollEvent(event))
	{
		switch(event.type)
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Return || event.key.code == Keyboard::Escape)
			{
				gameStatus = GameStatus::MAIN_MENU;
				break;
			}
	}

}
//this method exits game
void Game::ExitGame()
{
	window.close();
}

