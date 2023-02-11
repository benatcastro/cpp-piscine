#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void	PhoneBook::addContact(void) {
	static int	addIndex = 1;

	addIndex == 8 ? addIndex = 1 : addIndex;
	std::string	userInput;
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

void	PhoneBook::searchContact(void) {
	std::string		userInput;
	unsigned short	searchIndex;

	std::cout << std::endl << "Enter contact's index: ";
	std::cin >> userInput;
	while (!validateSearchIndex(userInput))
	{
		std::cout << "Invalid index" << std::endl << "Enter contacts's index:";
		std::cin >> userInput;
	}
	searchIndex = atoi(userInput.c_str());
	std::cout
			<< DISPLAYTABLE << std::endl << searchIndex
			<< std::endl << this->contactArray[searchIndex].getFirstName()
			<< std::endl << this->contactArray[searchIndex].getLastName()
			<< std::endl << this->contactArray[searchIndex].getNickName() << std::endl;
}

int main (void) {
	std::string	promptCmd;
	PhoneBook	phoneBook;

	std::cout << PROMPT;
	while (std::getline(std::cin, promptCmd))
	{
		std::cout << PROMPT;
		if (promptCmd == "ADD")
			phoneBook.addContact();
		else if (promptCmd == "SEARCH")
			phoneBook.searchContact();
		else if (promptCmd == "EXIT")
			break ;
	}
	std::cout << std::endl;
	return 0;
}
