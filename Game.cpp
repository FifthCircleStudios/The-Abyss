#include "Game.h"
#include <iostream>
#include <cstdlib>  // For system()
#include <thread>   // For std::this_thread::sleep_for()
#include <chrono>   // For std::chrono::seconds
#include <windows.h>
#include "Locations.h"

// Clear the console screen
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Display a splash screen
void Game::displaySplashScreen() {
    // Clear the screen
    clearScreen();

    // Splash screen animation
    std::cout << "Fifth Circle Studios" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause to simulate flashing effect
    clearScreen();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause again

    // Clear the splash screen
    clearScreen();
}

// Show the main menu
void Game::showMainMenu() {
    clearScreen();

    std::cout << "Main Menu\n";
    std::cout << "1. New Adventure\n";
    std::cout << "2. Load Adventure\n";
    std::cout << "3. Exit\n";
    std::cout << "Select an option (1-3): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(); // To ignore the newline character left in the input buffer

    switch (choice) {
    case 1:
        startNewAdventure();
        break;
    case 2:
        loadAdventure();
        break;
    case 3:
        std::cout << "Exiting the game. Goodbye!\n";
        ExitProcess(0); // Terminate the program
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option.\n";
        showMainMenu(); // Show the menu again
        break;
    }
}

Game::Game()
    : player("Hero", 100, 10),
    locations("locations.md"),  // Initialize locations with file path
    commandsHandler(locations)  // Initialize commandsHandler with locations
{
    player.setPosition(0, 0, 0); // Start at the Hole
}

void Game::run() {
    displaySplashScreen(); // Show the splash screen at the start
    showMainMenu(); // Show the main menu after the splash screen

    // Main game loop
    while (true) {
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting the game. Goodbye!\n";
            ExitProcess(0); // Terminate the program
            break;
        }
        else if (input == "help") {
            displayHelp();
        }
        else {
            processInput(input);
            clearScreen();
        }
    }
}

void Game::startNewAdventure() {
    clearScreen();
    std::cout << "Starting a new adventure...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    runAdventure();
}

void Game::loadAdventure() {
    clearScreen();
    std::cout << "Loading adventure...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // Implement loading logic here (e.g., load player state, locations, etc.)
    runAdventure();
}

void Game::runAdventure() {
    std::string input;
    std::cout << "Type 'help' for a list of commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting the game. Goodbye!\n";
            break;
        }
        else if (input == "help") {
            displayHelp();
        }
        else {
            processInput(input);
            clearScreen();
        }
    }
}

void Game::processInput(const std::string& command) {
    clearScreen();

    if (command == "location") {
        commandsHandler.getLocation(player);
    }
    else if (command == "inventory") {
        std::cout << "You check your inventory.\n";
    }
    else if (command == "go north") {
        player.setPosition(player.getXPos(), player.getYPos() + 1, player.getZPos());
        std::cout << "You move north.\n";
        commandsHandler.getLocation(player);
    }
    else if (command == "go south") {
        player.setPosition(player.getXPos(), player.getYPos() - 1, player.getZPos());
        std::cout << "You move south.\n";
        commandsHandler.getLocation(player);
    }
    else if (command == "go east") {
        player.setPosition(player.getXPos() + 1, player.getYPos(), player.getZPos());
        std::cout << "You move east.\n";
        commandsHandler.getLocation(player);
    }
    else if (command == "go west") {
        player.setPosition(player.getXPos() - 1, player.getYPos(), player.getZPos());
        std::cout << "You move west.\n";
        commandsHandler.getLocation(player);
    }
    else if (command == "go up") {
        player.setPosition(player.getXPos(), player.getYPos(), player.getZPos() + 1);
        std::cout << "You climb up.\n";
        commandsHandler.getLocation(player);
    }
    else if (command == "go down") {
        player.setPosition(player.getXPos(), player.getYPos(), player.getZPos() - 1);
        std::cout << "You climb down.\n";
        commandsHandler.getLocation(player);
    }
    else {
        std::cout << "Unknown command. Type 'help' for a list of commands.\n";
    }
}

void Game::displayHelp() const {
    clearScreen();
    std::cout << "Available commands:\n";
    std::cout << "  help           - Show this help message\n";
    std::cout << "  location       - Show the player's current location\n";
    std::cout << "  inventory      - Show player's inventory (not implemented)\n";
    std::cout << "  go north       - Move north\n";
    std::cout << "  go south       - Move south\n";
    std::cout << "  go east        - Move east\n";
    std::cout << "  go west        - Move west\n";
    std::cout << "  go up          - Climb up\n";
    std::cout << "  go down        - Climb down\n";
    std::cout << "  exit           - Exit the game\n";
}
