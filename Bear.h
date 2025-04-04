#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"
#include <string>

class Bear : public Animal {
public:
    // Constructor
    Bear(const std::string& name, int age, const std::string& sex, 
         const std::string& color, double weight, const std::string& birthDate, 
         const std::string& birthplace = "", const std::string& birthSeason = "");

    // Override getInfo method
    std::string getInfo() const override;

    // Method to display bear information
    void displayInfo() const override;
};

#endif  // BEAR_H
