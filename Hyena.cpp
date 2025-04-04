#include "Hyena.h"
#include <iostream>
#include <sstream>

// Constructor
Hyena::Hyena(const std::string& name, int age, const std::string& sex, 
             const std::string& color, double weight, const std::string& birthDate, 
             const std::string& birthplace, const std::string& birthSeason)
    : Animal("hyena", name, age, sex, color, weight, birthDate, birthplace, birthSeason) {}

// Method to display hyena information
void Hyena::displayInfo() const {  // Renamed from showInfo to displayInfo
    std::cout << "Hyena Info: "
              << "ID: " << getId() << ", Name: " << getName() << ", Age: " << getAge()
              << ", Sex: " << getSex() << ", Color: " << getColor() << ", Weight: " << getWeight()
              << " pounds, Birthplace: " << getBirthplace() << ", Birth Season: " << getBirthSeason()
              << ", Birth Date: " << getBirthDate() << std::endl;
}

// Override getInfo method
std::string Hyena::getInfo() const {
    std::stringstream ss;
    ss << "Hyena: " << getName() << ", Age: " << getAge()
       << ", Sex: " << getSex() << ", Color: " << getColor()
       << ", Weight: " << getWeight() << " lbs, Birthplace: " << getBirthplace()
       << ", Birth Season: " << getBirthSeason() << ", Birth Date: " << getBirthDate();
    return ss.str();
}