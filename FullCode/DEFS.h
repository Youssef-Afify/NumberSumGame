#pragma once

enum PlayingMode
{
	BREAK_MODE,
	ERASOR_MODE,
	PEN_MODE
};

enum MenuNumOfOptions
{
	HowToPlayNum = 1,
	OptionsNum = 3,
	MainMenuNum = 3,
	PackagesNum = 10,
	ExitScreenNum = 2
};

enum MainMenuOptions
{
	Play,
	HowToPlay,
	Exit
};

enum PackagesScreenOptions
{
	BackToMainMenu = 3,
	Kids,
	Beginner,
	Easy,
	Medium,
	Hard,
	Extreme,
	Hero,
	SuperHero,
	Champion
};

enum OptionsScreenChoices
{
	ToMainMenu,
	UpdatePlayerInfo,
	RestoreProgression
};

enum ExitScreenOptions
{
	No,
	Yes
};