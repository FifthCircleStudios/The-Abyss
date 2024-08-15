#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    // Constructor
    Player(const std::string& name, int health, int attackPower);

    // Getters
    std::string getName() const;
    int getHealth() const;
    int getAttackPower() const;
    int getXPos() const;
    int getYPos() const;
    int getZPos() const;
    void getPosition(int& x, int& y, int& z) const;

    // Setters
    void setHealth(int health);
    void setAttackPower(int attackPower);
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
    void climbUp();
    void climbDown();
    void setPosition(int x, int y, int z);

    // Combat Method
    void attack(Player& target);

    // Method to check if the player is alive
    bool isAlive() const;

private:
    std::string name;
    int health;
    int attackPower;
    int xPos, yPos, zPos; // Position in the Abyss (x, y, z coordinates)
};

#endif // PLAYER_H
