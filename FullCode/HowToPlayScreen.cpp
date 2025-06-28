#include"HowToPlayScreen.h"

#include"MainMenuScreen.h"

HowToPlayScreen::HowToPlayScreen() : Screen()
{
	SetEndOfScreen(HowToPlayNum);
}

HowToPlayScreen::~HowToPlayScreen()
{

}

void HowToPlayScreen::DisplayScreen() const
{
	std::cout << "Welcome To NumberSum Game!\n\n";
	std::cout << "The goal is to choose right numbers which leads to the right sum of all rows and columns\n\n";
	std::cout << "Controls: \n";
	std::cout << "Use arrows for moving, space to select options\n\n";
	std::cout << "Type 'p' in the game to activate Pen Mode\n";
	std::cout << "Type 'e' in the game to activate Erasor Mode\n";
	std::cout << "Type backspace to end the game\n\n";
	std::cout << "-> Got it!";
}

void HowToPlayScreen::UpdateScreen(Screen*& myScreen)
{
	delete myScreen;
	myScreen = new MainMenuScreen();
}