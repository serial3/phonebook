#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class PhoneBook {
private:
    std::string filename;

public:
    PhoneBook(const std::string& filename);
    ~PhoneBook();

    bool addNumber(const std::string& phoneNumber, const std::string& nationalCode);
    void expropriateNumber();
    void deleteNumber(const std::string& phoneNumber);
};

#endif