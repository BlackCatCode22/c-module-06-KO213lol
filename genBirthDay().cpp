#include <iostream>
#include <string>
#include <ctime> // Include for time functions

using namespace std;

// Function to generate a birth date from age and birth season
string getBirthday(int age, const string& birthSeason) {
    // Get the current year
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    int currentYear = 1900 + currentTime->tm_year;

    // Calculate the birth year based on the age
    int birthYear = currentYear - age;

    // Assign a month based on the season
    int birthMonth = 0;
    if (birthSeason == "spring") {
        birthMonth = 3; // March
    } else if (birthSeason == "summer") {
        birthMonth = 6; // June
    } else if (birthSeason == "fall") {
        birthMonth = 9; // September
    } else if (birthSeason == "winter") {
        birthMonth = 12; // December
    } else {
        // If the season is unknown, default to January
        birthMonth = 1;
    }

    if (birthSeason != "spring" && birthSeason != "summer" &&
        birthSeason != "fall" && birthSeason != "winter") {
        cerr << "Warning: Unknown birth season '" << birthSeason << "'. Defaulting to January." << endl;
        birthMonth = 1;
    }

    // Form the birth date as a string
    string birthDate = to_string(birthYear) + "-" + (birthMonth < 10 ? "0" : "") + to_string(birthMonth) + "-01";
    return birthDate;
}

// Example usage
int main() {
    cout << "Birthday Example 1: " << getBirthday(5, "spring") << endl;  // 2020-03-01
    cout << "Birthday Example 2: " << getBirthday(3, "winter") << endl;  // 2022-12-01
    cout << "Birthday Example 3: " << getBirthday(10, "summer") << endl;  // 2015-06-01
    return 0;
}
