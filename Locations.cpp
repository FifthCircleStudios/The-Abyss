#include "Locations.h"
#include <fstream>
#include <sstream>
#include <iostream>

Locations::Locations(const std::string& filePath) {
    loadLocationsFromFile(filePath);
}

void Locations::loadLocationsFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open locations file: " << filePath << std::endl;
        return;
    }

    std::string line;
    int x = 0, y = 0, z = 0;
    std::string name, description;

    while (std::getline(file, line)) {
        if (line.rfind("## (", 0) == 0) {  // Parse the coordinates
            sscanf_s(line.c_str(), "## (%d, %d, %d)", &x, &y, &z);
        }
        else if (line.rfind("- **Name**: ", 0) == 0) {  // Parse the location name
            name = line.substr(12);
        }
        else if (line.rfind("- **Description**: ", 0) == 0) {  // Parse the description
            description = line.substr(19);
            // Add the location to the map
            locationMap[{x, y, z}] = { name, description };
        }
    }

    file.close();
}

std::string Locations::getLocationName(int x, int y, int z) const {
    auto it = locationMap.find({ x, y, z });
    if (it != locationMap.end()) {
        return it->second.name;
    }
    else {
        return "Unknown Location";
    }
}

std::string Locations::getLocationDescription(int x, int y, int z) const {
    auto it = locationMap.find({ x, y, z });
    if (it != locationMap.end()) {
        return it->second.description;
    }
    else {
        return "There is nothing special about this place.";
    }
}
