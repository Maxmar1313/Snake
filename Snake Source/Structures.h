#pragma once
enum class GameStatus :unsigned char
{
	MAIN_MENU,
	IN_GAME,
	ENDGAME_SCREEN,
	HIGH_SCORE,
	EXIT_GAME,
};
struct highscoreEntity
{
	std::string name;
	unsigned int score;
};