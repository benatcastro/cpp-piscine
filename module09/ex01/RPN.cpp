#include "RPN.hpp"

RPN::RPN() { cout << "RPN constructed\n"; }

RPN::~RPN() { cout << "RPN destructed\n"; }

bool RPN::isSet(const std::string str, const std::string set) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		if (std::find(set.begin(), set.end(), *it) != set.end()) {
			return true;
		}
	return false;

}

void RPN::validateToken(const std::string token) {

	const string valid_chars = "+-/*";
	cout << "token: " << token << endl;
	if (token.at(0) == '-')
	{
		if (token.size() == 2 && !isdigit(token.at(1)))
			throw (std::invalid_argument("invalid token"));
	}
	else if (token.size() != 1)
	{
		throw (std::invalid_argument("unrecognized token"));
	}
	if (!RPN::isSet(token, valid_chars) && !isdigit(token.at(0)))
		throw (std::invalid_argument("invalid token"));

}

void RPN::checkArg(char *argv) {

	char	*token;
	string	separation;

	separation = " ";
	token = std::strtok(argv, separation.c_str());

	try {
		do {
			cout << token << " ";
			if (token)
			{
				validateToken(token);
				numbers.push(std::atoi(token));
			}
			token = std::strtok(NULL, separation.c_str());
		} while (token);
	}
	catch (std::exception &e)
	{
		cout << "Error: " << e.what() << endl;
	}
	cout << endl;


}
