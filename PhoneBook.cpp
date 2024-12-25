#include "PhoneBook.h"

PhoneBook::PhoneBook(const std::string& filename) : filename(filename) {}

PhoneBook::~PhoneBook() {
    // Close file if it is open
}

bool PhoneBook::addNumber(const std::string& phoneNumber, const std::string& nationalCode) {
    if (phoneNumber.length() < 3 || phoneNumber.length() > 5) {
        std::cerr << "Error: Phone number must be between 3 and 5 digits.\n";
        return false;
    }

    std::ofstream outFile(filename, std::ios::app);

    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return false;
    }

    std::ifstream inFile(filename);
    std::string line;
    bool numberExists = false;

    while (std::getline(inFile, line)) {
        std::size_t pos = line.find(' ');
        if (pos != std::string::npos) {
            std::string storedPhoneNumber = line.substr(0, pos);
            if (storedPhoneNumber == phoneNumber) {
                std::cerr << "Error: Phone number already exists.\n";
                numberExists = true;
                break;
            }
        }
    }

    inFile.close();

    if (numberExists) {
        return false;
    }

    outFile << phoneNumber << " " << "1" << " " << nationalCode << std::endl;
    std::cout << "Number added successfully.\n";

    outFile.close();
    return true;
}

void PhoneBook::expropriateNumber() {
    std::ifstream inFile(filename);
    std::ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        std::cerr << "Error opening file for reading or writing.\n";
        return;
    }

    std::string userPhoneNumber;
    std::string phoneNumber, status, nationalCode;
    bool found = false;

    std::cout << "Enter phone number to expropriate: ";
    std::cin >> userPhoneNumber;

    while (inFile >> phoneNumber >> status >> nationalCode) {
        if (phoneNumber == userPhoneNumber) {
            found = true;
            tempFile << phoneNumber << " " << "0" << " null\n";
            std::cout << "Number expropriated successfully.\n";
        } else {
            tempFile << phoneNumber << " " << status << " " << nationalCode << std::endl;
        }
    }

    if (!found) {
        std::cout << "Error: Phone number not found.\n";
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void PhoneBook::deleteNumber(const std::string& phoneNumber) {
    std::ifstream inFile(filename);
    std::ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        std::cerr << "Error opening file for reading or writing.\n";
        return;
    }

    std::string currentPhoneNumber, status, nationalCode;
    bool found = false;

    while (inFile >> currentPhoneNumber >> status >> nationalCode) {
        if (phoneNumber == currentPhoneNumber) {
            found = true;
            std::cout << "Number deleted successfully.\n";
        } else {
            tempFile << currentPhoneNumber << " " << status << " " << nationalCode << std::endl;
        }
    }

    if (!found) {
        std::cout << "Error: Phone number not found.\n";
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}