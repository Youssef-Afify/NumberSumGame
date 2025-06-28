#pragma once
#include<iostream>
#ifdef _WIN32
#include<conio.h>
#include<windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

class Terminal
{
private:

public:
	Terminal();
	void HideCursor();
	void ShowCursor();
	void CleanTerminal();
};
