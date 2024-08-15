// Credit To Full Sail PG2 Course For the Console Code, Saves me a good Hour.

#pragma once
#include <string>

enum ConsoleColor
{
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    Default = 9
};

class Console
{
public:
    static void ResizeWindow(int width, int height);
    static int GetWindowWidth() { return windowWidth; }
    static int GetWindowHeight() { return windowHeight; }
    static void SetCursorPosition(int x, int y);
    static void SetCursorLeft(int x);
    static void SetForegroundColor(ConsoleColor foreColor);
    static void SetForegroundColor(int r, int g, int b);
    static void SetBackgroundColor(ConsoleColor backColor);
    static void SetBackgroundColor(int r, int g, int b);
    static void Reset();
    static void Clear();

    static void Write(std::string message);
    static void Write(std::string message, ConsoleColor foreColor, ConsoleColor backColor = ConsoleColor::Black);
    static void WriteLine(std::string message);
    static void WriteLine(std::string message, ConsoleColor foreColor, ConsoleColor backColor = ConsoleColor::Black);
    static void WriteCentered(const std::string& message, ConsoleColor color);


private:
    static const std::string ESC;

    static int windowWidth, windowHeight;
};