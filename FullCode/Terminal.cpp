#include"Terminal.h"

Terminal::Terminal()
{
	
}

void Terminal::HideCursor() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;             // Hide
    SetConsoleCursorInfo(hOut, &cursorInfo);
#else
    std::cout << "\033[?25l";                // ANSI: Hide cursor
    std::cout.flush();
#endif
}

void Terminal::ShowCursor() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = TRUE;              // Show
    SetConsoleCursorInfo(hOut, &cursorInfo);
#else
    std::cout << "\033[?25h";                // ANSI: Show cursor
    std::cout.flush();
#endif
}

void Terminal::CleanTerminal()
{
    std::cout << "\033[1J";
    std::cout << "\033[1;1H";
}