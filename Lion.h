#ifndef LION_H
#define LION_H

#include "Animal.h"
#include <string>

class Lion : public Animal {
public:
    // Constructor
    Lion(const std::string& name, int age, const std::string& sex, 
         const std::string& color, double weight, const std::string& birthDate, 
         const std::string& birthplace = "", const std::string& birthSeason = "");

    // Override getInfo method
    std::string getInfo() const override;

    // Method to display lion information
    void displayInfo() const override;
};

#endif  // LION_H
