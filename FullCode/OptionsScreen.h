#pragma once
#include "Screen.h"
class MainMenuScreen;

class OptionsScreen : public Screen
{
private:

public:
	OptionsScreen();
	virtual ~OptionsScreen();
	virtual void DisplayScreen() const;
	virtual void UpdateScreen(Screen*&);
};