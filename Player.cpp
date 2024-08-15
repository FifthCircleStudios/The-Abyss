#include "Player.h"
#include <iostream>

// Constructor
Player::Player(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower), xPos(0), yPos(0), zPos(0) {}

// Getters
std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getAttackPower() const {
    return attackPower;
}

// Setters
void Player::setHealth(int health) {
    this->health = health;
}

void Player::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}

// Movement Methods
void Player::moveNorth() {
    yPos++;
    std::cout << name << " moves North.\n";
}

void Player::moveSouth() {
    yPos--;
    std::cout << name << " moves South.\n";
}

void Player::moveEast() {
    xPos++;
    std::cout << name << " moves East.\n";
}

void Player::moveWest() {
    xPos--;
    std::cout << name << " moves West.\n";
}

void Player::climbUp() {
    zPos++;
    std::cout << name << " climbs up.\n";
}

void Player::climbDown() {
    zPos--;
    std::cout << name << " climbs down.\n";
}
int Player::getXPos() const {
    return xPos;
}

int Player::getYPos() const {
    return yPos;
}

int Player::getZPos() const {
    return zPos;
}

void Player::getPosition(int& x, int& y, int& z) const {
    x = xPos;
    y = yPos;
    z = zPos;
}

void Player::setPosition(int x, int y, int z) {
    xPos = x;
    yPos = y;
    zPos = z;
}

// Combat Method
void Player::attack(Player& target) {
    std::cout << name << " attacks " << target.getName() << " for " << attackPower << " damage.\n";
    int newHealth = target.getHealth() - attackPower;
    target.setHealth(newHealth);
    if (!target.isAlive()) {
        std::cout << target.getName() << " has been defeated!\n";
    }
}

// Method to check if the player is alive
bool Player::isAlive() const {
    return health > 0;
}
