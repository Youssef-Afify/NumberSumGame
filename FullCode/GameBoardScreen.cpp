#include"GameBoardScreen.h"

#include"PackagesScreen.h"
#include<fstream>

void GameBoardScreen::CalcSums()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			RowSums[i] += Board[i][j].GetNumber() * Board[i][j].GetKey();
			ColSums[j] += Board[i][j].GetNumber() * Board[i][j].GetKey();
		}
	}
}

void GameBoardScreen::Restore()
{
	Hearts = (size - 4) / 3 + 3;
	SetCurrentChoice(1);
	CurrentColumn = 1;
	NumberOfCellsRemained = size * size;
	GameMode = ERASOR_MODE;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Board[i][j].Restore())
			{
				RowSums[i] += Board[i][j].GetNumber() * Board[i][j].GetKey();
				ColSums[j] += Board[i][j].GetNumber() * Board[i][j].GetKey();
			}
		}
	}
}

void GameBoardScreen::PrintHorizontalBorders() const
{
	std::cout << "\n-";
	for (int i = 0; i < size + 1; i++)
	{
		std::cout << "--------";
	}
	std::cout << '\n';
}

int GameBoardScreen::GetSize() const
{
	return size;
}

std::string GameBoardScreen::CurrentMode() const
{
	if (GameMode == ERASOR_MODE)
		return "Erasor Mode";
	return "Pen Mode";
}

void GameBoardScreen::ActivateErasor()
{
	GameMode = ERASOR_MODE;
}

void GameBoardScreen::ActivatePen()
{
	GameMode = PEN_MODE;
}

void GameBoardScreen::Check(int row, int col)
{
	row--;
	col--;
	if (row >= size || col >= size || Board[row][col].AlreadyChosen() || Board[row][col].AlreadyRemoved())
		return;
	if (Board[row][col].GetKey() == 1 && GameMode == PEN_MODE)
	{
		Board[row][col].Choose();
		RowSums[row] -= Board[row][col].GetNumber();
		ColSums[col] -= Board[row][col].GetNumber();
		NumberOfCellsRemained--;
	}
	else if (Board[row][col].GetKey() == 0 && GameMode == ERASOR_MODE)
	{
		Board[row][col].Remove();
		NumberOfCellsRemained--;
	}
	else
	{
		if (Hearts > 0)
			Hearts--;
		std::cout << "Wrong! ";
		if (Hearts > 0)
			system("PAUSE");
	}
}

GameBoardScreen::GameBoardScreen(int boardSize) : Screen(), size(boardSize > 0 ? boardSize : 1) , Hearts((size - 4) / 3 + 3), NumberOfCellsRemained(size* size), GameMode(PlayingMode::ERASOR_MODE)
{
	SetEndOfScreen((MenuNumOfOptions)(boardSize + 1));
	CurrentColumn = 1;
	SetCurrentChoice(1);
	srand(time(NULL));
	RowSums = new int[size];
	ColSums = new int[size];
	Board = new NumberPair * [size];
	for (int i = 0; i < size; i++)
	{
		RowSums[i] = 0;
		ColSums[i] = 0;
		Board[i] = new NumberPair[size];
	}
	CalcSums();
}

void GameBoardScreen::DisplayScreen() const
{
	std::cout << "Hearts: " << Hearts << ", " << CurrentMode();
	PrintHorizontalBorders();
	std::cout << "|\t|";
	for (int i = 0; i < size; i++)
	{
		if (ColSums[i] == 0)
			std::cout << " \t|";
		else
			std::cout << "   " << ColSums[i] << "\t|";
	}
	PrintHorizontalBorders();
	for (int i = 0; i < size; i++)
	{
		if (RowSums[i] == 0)
			std::cout << "|    \t|";
		else
			std::cout << "|   " << RowSums[i] << "\t|";
		for (int j = 0; j < size; j++)
		{
			if (i == GetCurrentChoice() - 1 && j == CurrentColumn - 1)
			{
				if (GameMode == PEN_MODE)
					std::cout << "=>";
				else
					std::cout << "<=";
			}
			else
				std::cout << "  ";
			if (Board[i][j].AlreadyRemoved())
				std::cout << "  \t|";
			else if (Board[i][j].AlreadyChosen())
				std::cout << " ~\t|";
			else
				std::cout << " " << Board[i][j].GetNumber() << "\t|";
		}
		PrintHorizontalBorders();
	}
}

bool GameBoardScreen::ReadScreenParameters()
{
#ifdef _WIN32
	int ch = _getch();
	if (ch == 224 || ch == 0) // Special keys
	{
		ch = _getch();
		switch (ch)
		{
		case 72: //"UP"
			if (GetCurrentChoice() > 1)
				SetCurrentChoice(GetCurrentChoice() - 1);
			else
				SetCurrentChoice(size);
			break;
		case 80: //"DOWN"
			if (GetCurrentChoice() < size)
				SetCurrentChoice(GetCurrentChoice() + 1);
			else
				SetCurrentChoice(1);
			break;
		case 77: //"RIGHT"
			if (CurrentColumn < size)
				CurrentColumn++;
			else
				CurrentColumn = 1;
			break;
		case 75: //"LEFT"
			if (CurrentColumn > 1)
				CurrentColumn--;
			else
				CurrentColumn = size;
			break;
		default:
			break;
		}
	}
	else if (ch == 8)
		GameMode = PlayingMode::BREAK_MODE;
	else if (ch == 32 || ch == 13)
		Check(GetCurrentChoice(), CurrentColumn);
	else if (ch == 80 || ch == 112)
		ActivatePen();
	else if (ch == 69 || ch == 101)
		ActivateErasor();
#else
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;

	newt.c_lflag &= ~(ICANON | ECHO);  // Disable line buffering and echo
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	char ch1 = getchar();
	std::string result;

	if (ch1 == '\033') { // Escape sequence
		char ch2 = getchar();
		char ch3 = getchar();

		if (ch2 == '[') {
			switch (ch3) {
			case 'A': //"UP"
				if (GetCurrentChoice() > 1)
					SetCurrentChoice(GetCurrentChoice() - 1);
				else
					SetCurrentChoice(size);
				break;
			case 'B': //"DOWN"
				if (GetCurrentChoice() < size)
					SetCurrentChoice(GetCurrentChoice() + 1);
				else
					SetCurrentChoice(1);
				break;
			case 'C': //"RIGHT"
				if (CurrentColumn < size)
					CurrentColumn++;
				else
					CurrentColumn = 1;
				break;
			case 'D': //"LEFT"
				if (CurrentColumn > 1)
					CurrentColumn--;
				else
					CurrentColumn = size;
				break;
			default:
				break;
			}
		}
	}
	else if ((int)ch == 8)
		GameMode = PlayingMode::BREAK_MODE;
	else if (ch1 == '\n' || ch1 == '\r' || ch1 == ' ') {
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal
		Check(GetCurrentChoice(), CurrentColumn);
	}
	else if (ch1 == 'p' || ch1 == 'P')
		ActivatePen();
	else if (ch1 == 'e' || ch1 == 'E')
		ActivateErasor();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal
#endif
	return (!(GameMode && Hearts && NumberOfCellsRemained));
}

void GameBoardScreen::UpdateScreen(Screen*& myScreen)
{
	myScreen->CleanTerminal();
	myScreen->DisplayScreen();
	if (GameMode == PlayingMode::BREAK_MODE)
	{
		delete myScreen;
		myScreen = new PackagesScreen();
		return;
	}
	if (NumberOfCellsRemained == 0)
		std::cout << "Congratulations!\n";
	else if (Hearts == 0)
	{
		std::cout << "Sorry...\n";
		system("PAUSE");
		Restore();
		return;
	}
	system("PAUSE");
	int size = dynamic_cast<GameBoardScreen*>(myScreen)->GetSize();
	delete myScreen;
	myScreen = new GameBoardScreen(size);
}

GameBoardScreen::~GameBoardScreen()
{
	delete[] RowSums;
	delete[] ColSums;
	RowSums = nullptr;
	ColSums = nullptr;
	for (int i = 0; i < size; i++)
	{
		delete[] Board[i];
		Board[i] = nullptr;
	}
	delete[] Board;
	Board = nullptr;
}