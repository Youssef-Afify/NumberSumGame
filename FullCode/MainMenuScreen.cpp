#include"MainMenuScreen.h"

#include"PackagesScreen.h"
#include"HowToPlayScreen.h"
#include"ExitScreen.h"

MainMenuScreen::MainMenuScreen() : Screen()
{
	SetEndOfScreen(MainMenuNum);
}

MainMenuScreen::~MainMenuScreen()
{

}

void MainMenuScreen::DisplayScreen() const
{
	std::string menuObjects[MainMenuNum] = {"Play", "How To Play", "Exit"};
	std::cout << "Welcome To NumberSum Game!\n\n";
	for (int i = 0; i < GetEndOfScreen(); i++)
	{
		if (i == GetCurrentChoice())
			std::cout << "-> ";
		else
			std::cout << "   ";
		std::cout << menuObjects[i] << std::endl;
	}
}

void MainMenuScreen::UpdateScreen(Screen*& myScreen)
{
	int NextScreen = GetCurrentChoice();
	delete myScreen;
	switch (NextScreen)
	{
	case MainMenuOptions::Play:
		myScreen = new PackagesScreen();
		break;
	case MainMenuOptions::HowToPlay:
		myScreen = new HowToPlayScreen();
		break;
	case MainMenuOptions::Exit:
		myScreen = new ExitScreen();
		break;
	default:
		break;
	}
}