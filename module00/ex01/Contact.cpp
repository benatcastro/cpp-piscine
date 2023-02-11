#include <iostream>
#include "Contact.hpp"

// Setters declaration for Contact

void	Contact::setFirstName(const std::string _firstName) {
	this->firstName = _firstName;
}

void	Contact::setLastName(const std::string _lastName) {
	this->lastName = _lastName;
}

void	Contact::setNickName(const std::string _nickName) {
	this->nickName = _nickName;
}

void	Contact::setPhoneNumber(const std::string _phoneNumber) {
	this->phoneNumber = _phoneNumber;
}

void	Contact::setSecret(const std::string _secret) {
	this->secret = _secret;
}

// Getters declarations for Contact

std::string Contact::getFirstName(void) {
	return this->firstName;
}

std::string Contact::getLastName(void) {
	return this->lastName;
}

std::string Contact::getNickName(void) {
	return this->nickName;
}

std::string Contact::getPhoneNumber(void) {
	return this->phoneNumber;
}

std::string Contact::getSecret(void) {
	return this->secret;
}
