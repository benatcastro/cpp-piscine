#include <string>
#include <iostream>

bool	validatePhoneNumber(std::string phoneNumber) {
	for (auto & c : phoneNumber)
		if (!isdigit(c))
			return false;
	return true;
}

bool	validateSearchIndex(std::string searchIndex) {
	for(auto & c : searchIndex)
		if (!isdigit(c) || c > '8' || c == '0')
			return false;
	return true;
}
