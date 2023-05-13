#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { cout << "Scalar converter constructed\n"; }

ScalarConverter::~ScalarConverter() { cout << "Scalar converter destructed\n"; }


 int16_t ScalarConverter::isNonLiteral(const std::string &arg, const std::string &nonLiteral) {

	std::size_t pos = arg.find(nonLiteral);

	if (pos != string::npos && pos < 2)
	{
		return (pos);
	}
	return (-1);


}

ScalarConverter::data_type ScalarConverter::parser(const __unused std::string &arg) {

	// Decapitalize string for so its not case sensitive anymore

	for (string::const_iterator it = arg.begin(); it != arg.end(); it++)
		tolower(*it);

	// Checks for non literals (NaN, +inf, -inf)

	if (isNonLiteral(arg, NaN) != -1)
		cout << "is nan\n";
	if (isNonLiteral(arg, INF) != -1)
		cout << "is inf\n";

	return (big_float);
}

void ScalarConverter::converter(const std::string __unused &arg) {}
