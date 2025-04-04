#include "Bear.h"
#include <iostream>
#include <sstream>

// Constructor
Bear::Bear(const std::string& name, int age, const std::string& sex, 
           const std::string& color, double weight, const std::string& birthDate, 
           const std::string& birthplace, const std::string& birthSeason)
    : Animal("bear", name, age, sex, color, weight, birthDate, birthplace, birthSeason) {}

// Method to display bear information
void Bear::displayInfo() const {
    std::cout << "Bear Info: "
              << "ID: " << getId() << ", Name: " << getName() << ", Age: " << getAge()
              << ", Sex: " << getSex() << ", Color: " << getColor() << ", Weight: " << getWeight()
              << " pounds, Birthplace: " << getBirthplace() << ", Birth Season: " << getBirthSeason()
              << ", Birth Date: " << getBirthDate() << std::endl;
}

// Override getInfo method
std::string Bear::getInfo() const {
    std::stringstream ss;
    ss << "Bear: " << getName() << ", Age: " << getAge()
       << ", Sex: " << getSex() << ", Color: " << getColor()
       << ", Weight: " << getWeight() << " lbs, Birthplace: " << getBirthplace()
       << ", Birth Season: " << getBirthSeason() << ", Birth Date: " << getBirthDate();
    return ss.str();
}