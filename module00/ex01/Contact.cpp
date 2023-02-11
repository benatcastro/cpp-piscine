#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact destructor called" << std::endl;
	return;
}

void Contact::addContact(void) {
	std::cout << "Enter contact Details" << std::endl;
	std::cout << "First name: ";
	std::cin >> this->firstName;
	std::cout << "[DEBUG] First Name:" << this->firstName << std::endl;
}
