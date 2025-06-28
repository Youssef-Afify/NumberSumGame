#pragma once
#include "Screen.h"
class MainMenuScreen;
class LevelsScreen;

class PackagesScreen : public Screen
{
private:

public:
	PackagesScreen();
	virtual ~PackagesScreen();
	//virtual bool ReadScreenParameters();
	virtual void DisplayScreen() const;
	virtual void UpdateScreen(Screen*&);
};