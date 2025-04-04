#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <memory>
#include <set>
#include "Animal.h"
#include "Hyena.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"

using namespace std;

vector<unique_ptr<Animal>> animals;
ofstream errorLog("error.log", ios::app);
set<string> unknownSpecies;

void logError(const string& message) {
    if (errorLog.is_open()) {
        errorLog << message << endl;
    }
    cerr << message << endl;
}

string genBirthDay(int age, const string& birthSeason) {
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    int currentYear = 1900 + currentTime->tm_year;

    int birthYear = currentYear - age;
    int birthMonth = 0;

    if (birthSeason == "spring") birthMonth = 3;
    else if (birthSeason == "summer") birthMonth = 6;
    else if (birthSeason == "fall") birthMonth = 9;
    else if (birthSeason == "winter") birthMonth = 12;
    else birthMonth = 1;

    string birthDate = to_string(birthYear) + "-" + (birthMonth < 10 ? "0" : "") + to_string(birthMonth) + "-01";

    // Debugging output
    cout << "Generated birth date: " << birthDate << " for age: " << age << " and birth season: " << birthSeason << endl;

    return birthDate;
}

vector<string> animalNames = {"Simba", "Nala", "ShereKhan", "Baloo", "Kamari", "Zuri"};

// Generate a random name for the animal
string getRandomName() {
    return animalNames[rand() % animalNames.size()];
}

// Parse a single line of animal data and create the appropriate object
void parseAnimalLine(const string& line) {
    stringstream ss(line);
    string name, species, sex, birthSeason, color, birthplace;
    int age;
    double weight;

    // Parse the fields
    ss >> name >> age >> sex >> species >> birthSeason >> color >> weight;
    getline(ss, birthplace); // Read the remaining part as birthplace
    if (!birthplace.empty() && birthplace[0] == ' ') {
        birthplace = birthplace.substr(1); // Remove leading space
    }

    // Debugging output
    cout << "Parsed line: " << line << endl;
    cout << "Name: " << name << ", Species: " << species << ", Age: " << age
         << ", Sex: " << sex << ", BirthSeason: " << birthSeason
         << ", Color: " << color << ", Weight: " << weight
         << ", Birthplace: " << birthplace << endl;

    // Validate the data
    if (species.empty() || age < 0 || weight <= 0) {
        logError("Invalid data: " + line);
        return;
    }

    // Generate the birth date
    string birthDate = genBirthDay(age, birthSeason);

    // Create the appropriate animal object
    if (species == "hyena") {
        animals.push_back(make_unique<Hyena>(name, age, sex, color, weight, birthDate, birthplace, birthSeason));
    } else if (species == "lion") {
        animals.push_back(make_unique<Lion>(name, age, sex, color, weight, birthDate, birthplace, birthSeason));
    } else if (species == "tiger") {
        animals.push_back(make_unique<Tiger>(name, age, sex, color, weight, birthDate, birthplace, birthSeason));
    } else if (species == "bear") {
        animals.push_back(make_unique<Bear>(name, age, sex, color, weight, birthDate, birthplace, birthSeason));
    } else {
        unknownSpecies.insert(species);
        logError("Unknown species: " + species);
    }
}

// Read animal data from the input file
bool readAnimalData(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        logError("Error opening input file: " + fileName);
        cerr << "Failed to open input file: " + fileName << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        parseAnimalLine(line);
    }
    file.close();
    return true;
}

// Generate the zoo population report
void generateReport(const string& fileName) {
    ofstream report(fileName);
    if (!report.is_open()) {
        logError("Error creating report file: " + fileName);
        return;
    }

    report << "Zoo Population Report\n";
    report << "=====================\n\n";

    for (const auto& animal : animals) {
        report << animal->getInfo() << endl;
    }

    report << "\nTotal Animals: " << animals.size() << endl;

    report.close();
}

// Log all unknown species encountered during parsing
void logUnknownSpecies() {
    if (!unknownSpecies.empty()) {
        stringstream ss;
        ss << "Unknown species encountered: ";
        for (const auto& species : unknownSpecies) {
            ss << species << " ";
        }
        logError(ss.str());
        cerr << ss.str() << endl;
    }
}

int main(int argc, char* argv[]) {
    srand(time(0)); // Seed random number generator

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    if (!readAnimalData(inputFile)) {
        return 1;
    }

    if (animals.empty()) {
        cerr << "No valid animals were processed. Exiting." << endl;
        return 1;
    }

    generateReport(outputFile);

    logUnknownSpecies();

    if (errorLog.is_open()) {
        errorLog.close();
    }

    return 0;
}
