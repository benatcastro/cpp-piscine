#include "ScalarConverter.hpp"

#define USAGE_HELPER "Usage: ./Converter <data that you want to convert>\n"


int main (int argc, char **argv)
{

	if (argc != 2)
		return (cout << USAGE_HELPER, 1);

	string arg(argv[1]);
	try {
		ScalarConverter::converter(arg);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << endl;
	}
}
