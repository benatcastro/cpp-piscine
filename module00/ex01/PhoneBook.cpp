#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

void	PhoneBook::addContact() {
	static int	addIndex = STARTINDEX;
	std::string	userInput;

    if (addIndex > MAXCONTACTS)
        addIndex = STARTINDEX;
	std::cout << std::endl << "Enter contact first name: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setFirstName(userInput);
	std::cout << "Enter contact's last name: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setLastName(userInput);
	std::cout << "Enter contact's nick name: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setPhoneNumber(userInput);
	std::cout << "Enter contact's phone number: ";
	std::cin >> userInput;
	while (!validatePhoneNumber(userInput))
	{
		std::cout << "Phone number is not valid" << std::endl << "Enter contact's phone number: ";
		std::cin >> userInput;
	}
	this->contactArray[addIndex].setNickName(userInput);
	std::cout << "Enter contact's darkest secret: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setSecret(userInput);
	addIndex++;
}

void	PhoneBook::searchContact() {
    std::string userInput;
    long        searchIndex;

	std::cout << std::endl << "Enter contact's index: ";
	std::cin >> userInput;
    if (!validateSearchIndex(userInput))
    {
        std::cerr << "Index must be an integer between 0 - 8" << std::endl;
        return;
    }
    searchIndex = std::strtol(userInput.c_str(), NULL, 10);
    if (!this->contactArray[searchIndex].getFirstName().length())
    {
        std::cout << "Contact number: " << searchIndex << " is not added" << std::endl;
        return;
    }
    // Print contact short desc
    std::cout << searchIndex << std::endl;
    if (contactArray[searchIndex].getFirstName().length() >= 10)
        std::cout << contactArray[searchIndex].getFirstName().replace(9, contactArray[searchIndex].getFirstName().length(), ".") << "|" << std::endl;
    else
        std::cout << std::setw(10) << contactArray[searchIndex].getFirstName() << "|" << std::endl;
    if (contactArray[searchIndex].getLastName().length() >= 10)
        std::cout << contactArray[searchIndex].getLastName().replace(9, contactArray[searchIndex].getLastName().length(), ".") << "|" << std::endl;
    else
        std::cout << std::setw(10) << contactArray[searchIndex].getLastName() << "|" << std::endl;
    if (contactArray[searchIndex].getNickName().length() >= 10)
        std::cout << contactArray[searchIndex].getNickName().replace(9, contactArray[searchIndex].getNickName().length(), ".") << "|" << std::endl;
    // Re prompt for index
    std::cout << std::endl << "Re enter contact's index: ";
    std::cin >> userInput;
    if (!validateSearchIndex(userInput))
    {
        std::cerr << "Index must be an integer between 0 - 8" << std::endl;
        return;
    }
    searchIndex = std::strtol(userInput.c_str(), NULL, 10);
    if (!this->contactArray[searchIndex].getFirstName().length())
    {
        std::cout << "Contact number: " << searchIndex << " is not added" << std::endl;
        return;
    }
    // Print full contact's info
    std::cout << "Contact's info:" << std::endl
            << "First name: " << contactArray[searchIndex].getFirstName() << std::endl
            << "Last name: " << contactArray[searchIndex].getLastName() << std::endl
            << "Nick name: " << contactArray[searchIndex].getNickName() << std::endl
            << "Phone Number: " << contactArray[searchIndex].getPhoneNumber() << std::endl
            << "Darkest secret: " << contactArray[searchIndex].getSecret() << std::endl;
}

int main () {
	PhoneBook	phoneBook;
	std::string	promptCmd;

	std::cout << PROMPT;
	while (std::getline(std::cin, promptCmd))
	{
		std::cout << PROMPT;
		if (promptCmd == "ADD")
			phoneBook.addContact();
		else if (promptCmd == "SEARCH")
			phoneBook.searchContact();
		else if (promptCmd == "EXIT")
			break;
	}
	std::cout << std::endl;
	return 0;
}

