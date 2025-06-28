#include "OptionsScreen.h"

#include"MainMenuScreen.h"

OptionsScreen::OptionsScreen() : Screen()
{
	SetEndOfScreen(OptionsNum);
	SetCurrentChoice(1);
}

OptionsScreen::~OptionsScreen()
{

}

void OptionsScreen::DisplayScreen() const
{
	std::string menuObjects[OptionsNum] = { "Main Menu", "Update Player's Info", "Restore Progression" };
	if (GetCurrentChoice() == 0)
		std::cout << "-> ";
	else
		std::cout << "   ";
	std::cout << menuObjects[0] << "\n\n";
	for (int i = 1; i < GetEndOfScreen(); i++)
	{
		if (i == GetCurrentChoice())
			std::cout << "-> ";
		else
			std::cout << "   ";
		std::cout << menuObjects[i] << "\n";
	}
}

void OptionsScreen::UpdateScreen(Screen*& myScreen)
{
	int NextScreen = GetCurrentChoice();
	switch (NextScreen)
	{
	case OptionsScreenChoices::ToMainMenu:
		delete myScreen;
		myScreen = new MainMenuScreen();
		break;
	case OptionsScreenChoices::UpdatePlayerInfo:
		// TODO
		break;
	case OptionsScreenChoices::RestoreProgression:
		// TODO
		break;
	}
}