#include"Screen.h"

#include"Terminal.h"

bool Screen::ReadScreenParameters()
{
#ifdef _WIN32
    int ch = _getch();
    if (ch == 224 || ch == 0) // Special keys
    {
        ch = _getch();
        switch (ch)
        {
        case 72: //return "UP";
            if (CurrentChoice > 0)
                CurrentChoice--;
            break;
        case 80: //return "DOWN";
            if (CurrentChoice < EndOfScreen - 1)
                CurrentChoice++;
            break;
        default: //return "UNKNOWN";
            break;
        }
        return false;
    }
    else if (ch == 32 || ch == 13) // enter or space
        return true;
    else
        return false;
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
            case 'A': //result = "UP"; break;
                if (CurrentChoice > 0)
                    CurrentChoice--;
                break;
            case 'B': //result = "DOWN"; break;
                if (CurrentChoice < EndOfScreen - 1)
                    CurrentChoice++;
                break;
            default: //result = "UNKNOWN";
                break;
            }
        }
        else {
            return false;
        }
    }
    else if (ch1 == '\n' || ch1 == '\r' || ch1 == ' ') {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal
        return true;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal
    return false;
#endif
}

Screen::Screen()
{
    CurrentChoice = 0;
    EndOfScreen = 0;
    pTerminal = new Terminal();
}

Screen::~Screen()
{
    if (pTerminal)
        delete pTerminal;
    pTerminal = nullptr;
}

int Screen::GetCurrentChoice() const
{
    return CurrentChoice;
}
int Screen::GetEndOfScreen() const
{
    return EndOfScreen;
}

void Screen::SetEndOfScreen(MenuNumOfOptions num)
{
    EndOfScreen = num;
}

void Screen::SetCurrentChoice(int num)
{
    CurrentChoice = (num > -1 && num < EndOfScreen) ? num : 0;
}

void Screen::CleanTerminal() const
{
    pTerminal->CleanTerminal();
}