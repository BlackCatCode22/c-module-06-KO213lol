#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"
#include <string>

class Tiger : public Animal {
public:
    // Constructor
    Tiger(const std::string& name, int age, const std::string& sex, 
          const std::string& color, double weight, const std::string& birthDate, 
          const std::string& birthplace = "", const std::string& birthSeason = "");

    // Override getInfo method
    std::string getInfo() const override;

    // Method to display tiger information
    void displayInfo() const override;
};

#endif  // TIGER_H
