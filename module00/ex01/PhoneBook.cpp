#include <iostream>
#include <string>
#include <map>
#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::addContact(void)
{
	std::cout << "add fnc" << std::endl;
}

void	PhoneBook::searchContact(void)
{
	std::cout << "search fnc" << std::endl;
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
		if (promptCmd == "EXIT")
			break ;
	}
	return 0;
}
