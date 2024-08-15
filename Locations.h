#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <string>
#include <map>
#include <tuple>

struct Location {
    std::string name;
    std::string description;
};

class Locations {
public:
    Locations(const std::string& filePath);
    std::string getLocationName(int x, int y, int z) const;
    std::string getLocationDescription(int x, int y, int z) const;

private:
    std::map<std::tuple<int, int, int>, Location> locationMap;

    void loadLocationsFromFile(const std::string& filePath);
};

#endif // LOCATIONS_H
