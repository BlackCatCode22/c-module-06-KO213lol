// filepath: c:\Users\ko165\OneDrive\Documents\Desktop\ZookeepersChalenge\animal.cpp
#include "animal.h"
#include <iostream>
#include <sstream>
#include <map>

// Define the static member
std::map<std::string, int> Animal::speciesCount;

// Constructor with optional birthplace and birthSeason
Animal::Animal(const std::string& species, const std::string& n, int a, const std::string& s,
               const std::string& c, double w, const std::string& date,
               const std::string& b, const std::string& season)
    : name(n), age(a), sex(s), color(c), weight(w), birthDate(date), birthplace(b), birthSeason(season) {
    // Generate unique ID for the species
    id = genUniqueID(species);

    // Validate input
    if (age < 0) {
        throw std::invalid_argument("Age cannot be negative for animal: " + name);
    }
    if (weight <= 0) {
        throw std::invalid_argument("Weight must be greater than zero for animal: " + name);
    }
    if (birthDate.empty()) {
        throw std::invalid_argument("Birth date cannot be empty for animal: " + name);
    }
}

// Default constructor
Animal::Animal()
    : id(""), name(""), sex(""), color(""), birthplace(""), birthSeason(""), birthDate(""),
      age(0), weight(0.0) {}

// Virtual destructor
Animal::~Animal() {}

// Generate a unique ID for the species
std::string Animal::genUniqueID(const std::string& species) {
    // Assign species code
    std::string speciesCode;
    if (species == "hyena") {
        speciesCode = "Hy";
    } else if (species == "lion") {
        speciesCode = "Li";
    } else if (species == "tiger") {
        speciesCode = "Ti";
    } else if (species == "bear") {
        speciesCode = "Be";
    } else {
        speciesCode = "XX";  // Default for unknown species
        std::cerr << "Warning: Unknown species encountered: " << species << std::endl;
    }

    // Increment count for this species
    speciesCount[species]++;

    // Format as two-digit number (01, 02, ..., 10, etc.)
    return speciesCode + (speciesCount[species] < 10 ? "0" : "") + std::to_string(speciesCount[species]);
}

// Getters for the private members
const std::string& Animal::getId() const { return id; }
const std::string& Animal::getName() const { return name; }
const std::string& Animal::getSex() const { return sex; }
const std::string& Animal::getColor() const { return color; }
const std::string& Animal::getBirthplace() const { return birthplace; }
const std::string& Animal::getBirthSeason() const { return birthSeason; }
const std::string& Animal::getBirthDate() const { return birthDate; }
int Animal::getAge() const { return age; }
double Animal::getWeight() const { return weight; }
