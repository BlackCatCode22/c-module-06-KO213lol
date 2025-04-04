#include "Lion.h"
#include <iostream>
#include <sstream>

// Constructor
Lion::Lion(const std::string& name, int age, const std::string& sex, 
           const std::string& color, double weight, const std::string& birthDate, 
           const std::string& birthplace, const std::string& birthSeason)
    : Animal("lion", name, age, sex, color, weight, birthDate, birthplace, birthSeason) {}

// Method to display lion information
void Lion::displayInfo() const {
    std::cout << "Lion Info: "
              << "ID: " << getId() << ", Name: " << getName() << ", Age: " << getAge()
              << ", Sex: " << getSex() << ", Color: " << getColor() << ", Weight: " << getWeight()
              << " pounds, Birthplace: " << getBirthplace() << ", Birth Season: " << getBirthSeason()
              << ", Birth Date: " << getBirthDate() << std::endl;
}

// Override getInfo method
std::string Lion::getInfo() const {
    std::stringstream ss;
    ss << "Lion: " << getName() << ", Age: " << getAge()
       << ", Sex: " << getSex() << ", Color: " << getColor()
       << ", Weight: " << getWeight() << " lbs, Birthplace: " << getBirthplace()
       << ", Birth Season: " << getBirthSeason() << ", Birth Date: " << getBirthDate();
    return ss.str();
}