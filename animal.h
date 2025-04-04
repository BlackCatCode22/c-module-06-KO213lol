#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <map>

class Animal {
protected:
    std::string id;
    std::string name;
    int age;
    std::string sex;
    std::string color;
    double weight;
    std::string birthplace;
    std::string birthSeason;
    std::string birthDate;

    static std::map<std::string, int> speciesCount;

protected:
    std::string genUniqueID(const std::string& species);

public:
    Animal(const std::string& species, const std::string& name, int age, const std::string& sex,
           const std::string& color, double weight, const std::string& birthDate,
           const std::string& birthplace = "", const std::string& birthSeason = "");

    Animal();
    virtual ~Animal();

    const std::string& getId() const;
    const std::string& getName() const;
    const std::string& getSex() const;
    const std::string& getColor() const;
    const std::string& getBirthplace() const;
    const std::string& getBirthSeason() const;
    const std::string& getBirthDate() const;
    int getAge() const;
    double getWeight() const;

    virtual std::string getInfo() const = 0;  // Pure virtual method
    virtual void displayInfo() const = 0;    // Pure virtual method
};

#endif  // ANIMAL_H
