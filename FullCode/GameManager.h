#pragma once
class Screen;

class GameManager
{
private:
	Screen* pScreen;
	void GetUserInput();
	void ExecuteAction() const;
	bool HasActiveScreen() const;
public:
	GameManager();
	~GameManager();
	void runApp();
};