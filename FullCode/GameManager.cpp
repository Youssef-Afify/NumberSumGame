#include"GameManager.h"

#include"Screen.h"
#include"MainMenuScreen.h"

GameManager::GameManager() : pScreen(new MainMenuScreen())
{
	
}

GameManager::~GameManager()
{
	if (pScreen)
		delete pScreen;
	pScreen = nullptr;
}

void GameManager::GetUserInput()
{
	if (pScreen->ReadScreenParameters())
		pScreen->UpdateScreen(pScreen);
}

void GameManager::ExecuteAction() const
{
	pScreen->CleanTerminal();
	pScreen->DisplayScreen();
}

bool GameManager::HasActiveScreen() const
{
	return (pScreen != nullptr);
}

void GameManager::runApp()
{
	do
	{
		ExecuteAction();
		GetUserInput();
	} while (HasActiveScreen());
}