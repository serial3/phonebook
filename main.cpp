#include <iostream>
#include "PhoneBook.h"

int main() {
    PhoneBook phoneBook("phonebook.txt");
    int choice;

    do {
        std::cout << "1. Add Number\n";
        std::cout << "2. Expropriate Number\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string phoneNumber, nationalCode;
                std::cout << "Enter phone number: ";
                std::cin >> phoneNumber;
                std::cout << "Enter national code: ";
                std::cin >> nationalCode;
                if (phoneBook.addNumber(phoneNumber, nationalCode)) {
                    std::cout << "Number added successfully.\n";
                }
                break;
            }
            case 2:
                phoneBook.expropriateNumber();
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}