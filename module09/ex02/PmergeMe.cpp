#include "PmergeMe.hpp"

bool isValidInteger(string str)
{
	if (str.empty())
		return false;

	for (string::iterator it = str.begin(); it != str.end(); it++)
		if (!isdigit(*it))
			return false;
	return true;
}

void parseInput(std::list<int> &input_list, int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (isValidInteger(argv[i]))
			input_list.push_back(std::atoi(argv[i]));
		else
			throw (std::invalid_argument("invalid integer as argument"));
	}

}
