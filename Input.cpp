#include "Input.h"
#include <iostream>

void Input::PressEnter(bool silent)
{
	if(!silent) std::cout << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Input::GetMenuSelection(std::vector<std::string> menuOptions, std::string message)
{
	//show the menu options
	//get the user's selection

	for (auto& option : menuOptions)
	{
		std::cout << option << std::endl;
	}
	return GetInteger(message, 1, (int)menuOptions.size());

}

std::string Input::GetString(std::string message)
{
	std::cout << "\n" << message << " ";
	std::string usersInput;
	std::getline(std::cin, usersInput);
	return usersInput;
}

int Input::GetInteger(std::string message, int min, int max)
{
	int number = 0;
	while (true)
	{
		std::cout << "\n" << message;
		if (std::cin >> number && number >= min && number <= max)
		{
			ClearInputBuffer();
			break;
		}
		ClearInputBuffer();
		std::cout << "\nInvalid number.\n";
	}
	return number;
}



void Input::ClearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

// New function to display centered message and wait for Enter key
void Input::PressEnterCentered(const std::string& message)
{
	// Get the width of the console window (you may need to adjust this based on your console)
	const int consoleWidth = 80; // Adjust based on your console's width

	// Calculate the position to start the message
	int messageLength = message.length();
	int padding = (consoleWidth - messageLength) / 2;

	// Print spaces to center the message
	std::cout << std::string(padding, ' ') << message << std::endl;
	PressEnter();  // Wait for Enter key
}