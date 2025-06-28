#pragma once
#include "Screen.h"
class MainMenuScreen;

class ExitScreen : public Screen
{
private:

public:
	ExitScreen();
	virtual ~ExitScreen();
	virtual void DisplayScreen() const;
	virtual void UpdateScreen(Screen*&);
};