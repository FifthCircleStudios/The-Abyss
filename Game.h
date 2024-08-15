#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "CommandsHandler.h"
#include "Locations.h"

class Game {
public:
    Game();
    void run();

private:
    Player player;
    CommandsHandler commandsHandler;
    Locations locations;
    void processInput(const std::string& command);
    void displayHelp() const;
    void displaySplashScreen();
    void showMainMenu();
    void startNewAdventure();
    void loadAdventure();
    void runAdventure();
};

#endif // GAME_H
