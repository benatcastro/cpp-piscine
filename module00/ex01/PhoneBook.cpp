#include <iostream>
#include <string>
#include "PhoneBook.hpp"

bool	validatePhoneNumber(std::string phoneNumber) {
	for (auto & c : phoneNumber)
		if (!isdigit(c))
			return false;
	return true;

}

void	PhoneBook::addContact(void) {
	static int	addIndex = 1;

	addIndex == 8 ? addIndex = 1 : addIndex;
	std::string	userInput;
	std::cout << std::endl << "Enter contact first name: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setFirstName(userInput);
	std::cout << "Enter contact last name: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setLastName(userInput);
	std::cout << "Enter contact nick name: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setPhoneNumber(userInput);
	std::cout << "Enter contact phone number: ";
	std::cin >> userInput;
	while (!validatePhoneNumber(userInput))
	{
		std::cout << "Phone number is not valid" << std::endl;
		std::cout << "Enter contact phone number: ";
		std::cin >> userInput;
	}
	this->contactArray[addIndex].setNickName(userInput);
	std::cout << "Enter contact darkest secret: ";
	std::cin >> userInput;
	this->contactArray[addIndex].setSecret(userInput);
	addIndex++;
}

void	PhoneBook::searchContact(void) {
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
