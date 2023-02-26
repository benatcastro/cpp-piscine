#include <string>

bool	validatePhoneNumber(std::string phoneNumber) {
	for (std::string::iterator it = phoneNumber.begin(); it != phoneNumber.end(); it++)
		if (!isdigit(*it))
			return false;
	return true;
}

bool	validateSearchIndex(std::string searchIndex) {
	for(std::string::iterator it = searchIndex.begin(); it != searchIndex.end(); it++)
		if (!isdigit(*it) || *it > '7')
			return (false);
        if (std::strtol(searchIndex.c_str(), NULL, 10) > 7)
            return (false);
	return true;
}
