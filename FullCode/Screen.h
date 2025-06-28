#pragma once
#include<iostream>
#include<string>
#include"DEFS.h"
#ifdef _WIN32
#include<conio.h>
#include<windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

class Terminal;

class Screen
{
private:
	int EndOfScreen;
	int CurrentChoice;
	Terminal* pTerminal;
public:
	Screen();
	int GetCurrentChoice() const;
	int GetEndOfScreen() const;
	void SetEndOfScreen(MenuNumOfOptions);
	void SetCurrentChoice(int);
	virtual ~Screen();
	virtual bool ReadScreenParameters();
	void CleanTerminal() const;
	virtual void DisplayScreen() const = 0;
	virtual void UpdateScreen(Screen*&) = 0;
};

//MainMenu Screen
//HowToPlay Screen
//Packages Screen
//InGame Screen
//Exit Screen

//Options Screen
//Player Info Screen
//Edit Player Info Screen

//Levels Screen