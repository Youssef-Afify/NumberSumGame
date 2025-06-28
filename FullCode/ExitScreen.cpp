#include "ExitScreen.h"

#include"MainMenuScreen.h"

ExitScreen::ExitScreen() : Screen()
{
	SetEndOfScreen(ExitScreenNum);
}

ExitScreen::~ExitScreen()
{

}

void ExitScreen::DisplayScreen() const
{
	std::string menuObjects[ExitScreenNum] = { "No", "Yes" };
	std::cout << "Are you sure you want to exit?\n\n";
	for (int i = 0; i < GetEndOfScreen(); i++)
	{
		if (i == GetCurrentChoice())
			std::cout << "-> ";
		else
			std::cout << "   ";
		std::cout << menuObjects[i] << std::endl;
	}
}

void ExitScreen::UpdateScreen(Screen*& myScreen)
{
	int NextScreen = GetCurrentChoice();
	delete myScreen;
	switch (NextScreen)
	{
	case ExitScreenOptions::No:
		myScreen = new MainMenuScreen();
		break;
	case ExitScreenOptions::Yes:
		myScreen = nullptr;
		break;
	default:
		myScreen = nullptr;
		break;
	}
}