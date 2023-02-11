#include <string>
#include <iostream>

bool	validatePhoneNumber(std::string phoneNumber) {
	for (std::string::iterator it = phoneNumber.begin(); it != phoneNumber.end(); it++)
		if (!isdigit(*it))
			return false;
	return true;
}

bool	validateSearchIndex(std::string searchIndex) {
	for(std::string::iterator it = searchIndex.begin(); it != searchIndex.end(); it++)
		if (!isdigit(*it) || *it > '8' || *it == '0')
			return false;
	return true;
}
