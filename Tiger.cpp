#include "Tiger.h"
#include <iostream>
#include <sstream>

// Constructor
Tiger::Tiger(const std::string& name, int age, const std::string& sex, 
             const std::string& color, double weight, const std::string& birthDate, 
             const std::string& birthplace, const std::string& birthSeason)
    : Animal("tiger", name, age, sex, color, weight, birthDate, birthplace, birthSeason) {}

// Method to display tiger information
void Tiger::displayInfo() const {
    std::cout << "Tiger Info: "
              << "ID: " << getId() << ", Name: " << getName() << ", Age: " << getAge()
              << ", Sex: " << getSex() << ", Color: " << getColor() << ", Weight: " << getWeight()
              << " pounds, Birthplace: " << getBirthplace() << ", Birth Season: " << getBirthSeason()
              << ", Birth Date: " << getBirthDate() << std::endl;
}

// Override getInfo method
std::string Tiger::getInfo() const {
    std::stringstream ss;
    ss << "Tiger: " << getName() << ", Age: " << getAge()
       << ", Sex: " << getSex() << ", Color: " << getColor()
       << ", Weight: " << getWeight() << " lbs, Birthplace: " << getBirthplace()
       << ", Birth Season: " << getBirthSeason() << ", Birth Date: " << getBirthDate();
    return ss.str();
}