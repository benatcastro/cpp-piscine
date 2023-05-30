#include "RPN.hpp"

RPN::RPN() {
	if (VERBOSE)
		cout << "RPN constructed\n";
}

RPN::~RPN() {
	if (VERBOSE)
		cout << "RPN destructed\n";
}

bool RPN::isSet(const std::string str, const std::string set) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		if (std::find(set.begin(), set.end(), *it) != set.end()) {
			return true;
		}
	return false;

}

void RPN::validateToken(const std::string token) {

	const string valid_chars = "+-/*";
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

void RPN::calculate(char operation) {

	int x,y = {0};
	if (this->numbers.size() > 3 || this->numbers.size() == 0)
		throw (std::runtime_error("invalid operation"));
	if (this->numbers.size())
	{
		x = this->numbers.top();
		this->numbers.pop();
	}
	if (this->numbers.size())
	{
		y = this->numbers.top();
		this->numbers.pop();
	}
	std::swap(x, y);
	switch (operation) {
		case '+':
			this->numbers.push(x + y);
			break;
		case '-':
			this->numbers.push(x - y);
			break;
		case '*':
			this->numbers.push(x * y);
			break;
		case '/':
			if (y == 0)
				throw (std::invalid_argument("can't divide by 0"));
			this->numbers.push(x / y);
			break;
		default:
			break;
	}
}

void RPN::checkArg(char *argv) {

	char	*token;
	string	separation;
	string	operators;

	separation = " ";
	operators = "+-/*";
	token = std::strtok(argv, separation.c_str());

	try {
		do {
			if (token)
			{
				validateToken(token);
				if (RPN::isSet(token, operators))
				{
					this->calculate(token[0]);
					token = std::strtok(NULL, separation.c_str());
					continue;
				}
				numbers.push(std::atoi(token));
			}
			token = std::strtok(NULL, separation.c_str());
		} while (token);
		if (this->numbers.size() != 1)
		{
			cerr << "Error: invalid operation\n";
		}
		else
		{
			cout <<  "Result: " << this->numbers.top() << endl;
		}
	}
	catch (std::exception &e)
	{
		cerr << "Error: " << e.what() << endl;
		return;
	}
}
