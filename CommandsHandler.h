#ifndef COMMANDSHANDLER_H
#define COMMANDSHANDLER_H

#include "Player.h"
#include <string>
#include <map>

#include "Locations.h"

class CommandsHandler {
public:
    // Constructor
    CommandsHandler(Locations& locs);

    // Command to create a new player
    Player* createPlayer(const std::string& name, int health, int attackPower);

    // Command to handle movement
    void handleMovement(Player& player, const std::string& direction); // Ensure this is declared

    // Command to open inventory (for now, just a placeholder)
    void openInventory();

    // Command to get the player's current location
    void getLocation(const Player& player);

    // Command to process user input
    void processCommand(Player& player, const std::string& command);
    void movePlayer(Player& player, const std::string& direction);

private:
    Player* player;

    // Helper method to convert command strings to function pointers
    typedef void (CommandsHandler::* CommandFunction)(Player&, const std::string&);
    std::map<std::string, CommandFunction> commandMap;

    // Initialize the command map
    void initializeCommandMap();
    Locations& locations;
    // Command functions
    bool canMove(const Player& player, const std::string& direction) const;
    void moveCommand(Player& player, const std::string& direction);
    void locationCommand(Player& player, const std::string& args);
    void inventoryCommand(Player& player, const std::string& args);
};

#endif // COMMANDSHANDLER_H
