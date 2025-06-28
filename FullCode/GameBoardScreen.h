#pragma once
#include"NumberPair.h"
#include"Screen.h"

class GameBoardScreen : public Screen
{
private:
	const int size;
	NumberPair** Board;
	int* RowSums;
	int* ColSums;
	int Hearts;
	int NumberOfCellsRemained;
	int GameMode;
	int CurrentColumn;
	std::string CurrentMode() const;
	int GetSize() const;
	void CalcSums();
	void PrintHorizontalBorders() const;
	void ActivateErasor();
	void ActivatePen();
	void Check(int row, int col);
	void Restore();
public:
	GameBoardScreen(int boardSize = 0);
	virtual void DisplayScreen() const;
	virtual bool ReadScreenParameters();
	virtual void UpdateScreen(Screen*&);
	~GameBoardScreen();
};