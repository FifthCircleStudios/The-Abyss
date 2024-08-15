#pragma once
#include <string>
#include <vector>

class Input
{
public:
    static std::string GetString(std::string message);
    static int GetInteger(std::string message, int min, int max);
    static int GetMenuSelection(std::vector<std::string> menuOptions, std::string message = "Choice? ");
    static void PressEnter(bool silent = false);
    static void PressEnterCentered(const std::string& message);  // Add this line

private:
    static void ClearInputBuffer();
};
