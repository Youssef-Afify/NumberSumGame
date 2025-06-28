#pragma once
#include"Screen.h"
class MainMenuScreen;

class HowToPlayScreen : public Screen
{
private:

public:
	HowToPlayScreen();
	virtual ~HowToPlayScreen();
	virtual void DisplayScreen() const;
	virtual void UpdateScreen(Screen*&);
};