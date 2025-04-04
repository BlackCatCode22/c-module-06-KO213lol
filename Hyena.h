#ifndef HYENA_H
#define HYENA_H

#include "Animal.h"
#include <string>

class Hyena : public Animal {
public:
    Hyena(const std::string& name, int age, const std::string& sex, const std::string& color,
          double weight, const std::string& birthDate, const std::string& birthplace = "",
          const std::string& birthSeason = "");

    std::string getInfo() const override;
    void displayInfo() const override;  // Correct method name
};

#endif  // HYENA_H
