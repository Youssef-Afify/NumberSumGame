#pragma once
#include"Screen.h"
class PackagesScreen;
class HowToPlayScreen;
class OptionsScreen;
class ExitScreen;

class MainMenuScreen : public Screen
{
private:
	
public:
	MainMenuScreen();
	virtual ~MainMenuScreen();
	virtual void DisplayScreen() const;
	virtual void UpdateScreen(Screen*&);
};