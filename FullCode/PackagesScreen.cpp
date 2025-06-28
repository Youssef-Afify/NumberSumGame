#include "PackagesScreen.h"

#include"MainMenuScreen.h"
#include"GameBoardScreen.h"

PackagesScreen::PackagesScreen() : Screen()
{
	SetEndOfScreen(PackagesNum);
	SetCurrentChoice(1);
}

PackagesScreen::~PackagesScreen()
{

}

void PackagesScreen::DisplayScreen() const
{
	std::string menuObjects[PackagesNum] = 
	{ 
		"Main Menu",
		"Kids (4 * 4)", "Beginner (5 * 5)", "Easy (6 * 6)",
		"Medium (7 * 7)", "Hard (8 * 8)", "Extreme (9 * 9)",
		"Hero (10 * 10)", "Super Hero (11 * 11)", "Champion (12 * 12)"
	};
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

void PackagesScreen::UpdateScreen(Screen*& myScreen)
{
	int NextScreen = GetCurrentChoice() + 3;
	delete myScreen;
	switch (NextScreen)
	{
	case PackagesScreenOptions::BackToMainMenu:
		myScreen = new MainMenuScreen();
		break;
	default:
		myScreen = new GameBoardScreen(NextScreen);
		break;
	}
}