#include "CommandsHandler.h"
#include <iostream>

#include "Locations.h"

// Constructor
CommandsHandler::CommandsHandler(Locations& locs) : locations(locs), player(nullptr) 
{
	initializeCommandMap();
}

// Initialize the command map with command strings and corresponding functions
void CommandsHandler::initializeCommandMap() {
    commandMap["go"] = &CommandsHandler::moveCommand;
    commandMap["location"] = &CommandsHandler::locationCommand;
    commandMap["inventory"] = &CommandsHandler::inventoryCommand;
}

// Command to create a new player
Player* CommandsHandler::createPlayer(const std::string& name, int health, int attackPower) {
    player = new Player(name, health, attackPower);
    std::cout << "Player " << name << " created with " << health << " health and " << attackPower << " attack power.\n";
    return player;
}
bool CommandsHandler::canMove(const Player& player, const std::string& direction) const {
    // Example logic to determine if the player can move in the given direction
    // You should replace this with your own logic based on your game rules
    if (direction == "north" || direction == "south" || direction == "east" || direction == "west" || direction == "up" || direction == "down") {
        return true;
    }
    return false;
}

void CommandsHandler::movePlayer(Player& player, const std::string& direction) {
    if (!canMove(player, direction)) {
        std::cout << "You can't move in that direction.\n";
        return;
    }

    handleMovement(player, direction);

    std::string locationName = locations.getLocationName(player.getXPos(), player.getYPos(), player.getZPos());
    std::string locationDescription = locations.getLocationDescription(player.getXPos(), player.getYPos(), player.getZPos());

    std::cout << "You arrive at " << locationName << ".\n";
    std::cout << locationDescription << "\n";
}

void CommandsHandler::handleMovement(Player& player, const std::string& direction) {
    if (direction == "north") {
        player.moveNorth();
    }
    else if (direction == "south") {
        player.moveSouth();
    }
    else if (direction == "east") {
        player.moveEast();
    }
    else if (direction == "west") {
        player.moveWest();
    }
    else if (direction == "up") {
        player.climbUp();
    }
    else if (direction == "down") {
        player.climbDown();
    }

    std::cout << "You move " << direction << ".\n";
}

// Command to open inventory (for now, just a placeholder)
void CommandsHandler::openInventory() {
    std::cout << "Opening inventory...\n";
    // Inventory management code goes here
}

// Command to get the player's current location
void CommandsHandler::getLocation(const Player& player) {
    Locations locations("Locations.md");
    std::string locationName = locations.getLocationName(player.getXPos(), player.getYPos(), player.getZPos());
    std::string locationDescription = locations.getLocationDescription(player.getXPos(), player.getYPos(), player.getZPos());

    std::cout << "You are at: " << locationName << "\n";
    std::cout << locationDescription << "\n";
}
// Command to process user input
void CommandsHandler::processCommand(Player& player, const std::string& command) {
    size_t spaceIndex = command.find(' ');
    std::string commandType = command.substr(0, spaceIndex);
    std::string commandArgs = (spaceIndex != std::string::npos) ? command.substr(spaceIndex + 1) : "";

    if (commandMap.find(commandType) != commandMap.end()) {
        (this->*commandMap[commandType])(player, commandArgs);
    }
    else {
        std::cout << "Unknown command: " << command << "\n";
    }
}

// Command functions
void CommandsHandler::moveCommand(Player& player, const std::string& direction) {
    handleMovement(player, direction);
}

void CommandsHandler::locationCommand(Player& player, const std::string& args) {
    getLocation(player);
}

void CommandsHandler::inventoryCommand(Player& player, const std::string& args) {
    openInventory();
}
