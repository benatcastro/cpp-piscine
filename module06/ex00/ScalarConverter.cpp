#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { cout << "Scalar converter constructed\n"; }

ScalarConverter::~ScalarConverter() { cout << "Scalar converter destructed\n"; }


ScalarConverter::data_type	ScalarConverter::isNaN(std::string &arg) { return ((arg.compare(NaN) == 0) ? not_a_number : not_found); }

ScalarConverter::data_type	ScalarConverter::isInf(std::string &arg) {

	if (!arg.compare(INF))
		return (plus_infinite);
	else if (!arg.compare("+inf"))
		return (plus_infinite);
	else if (!arg.compare("-inf"))
		return (neg_infinite);
	return (not_found);
}

ScalarConverter::data_type ScalarConverter::parser(std::string &arg) {

	// Decapitalize string for so its not case sensitive anymore

	for (string::iterator it = arg.begin(); it != arg.end(); it++)
		*it = tolower(*it);

	// Checks for non literals (NaN, +inf, -inf)

	data_type rvalue;

	rvalue = isNaN(arg);
	if (rvalue != not_found)
		return rvalue;
	rvalue = isInf(arg);
	if (rvalue != not_found)
		return rvalue;

	return (big_float);
}


void ScalarConverter::print_char(std::string __unused &arg, ScalarConverter::data_type __unused type) {

	char c;

	cout << "char: ";
	try {
		c = static_cast<char>(std::stoi(arg));

	}
	catch (std::exception &e) {
		if (type == not_a_number)
			cout << "impossible";
		else
			cout << "impossible";
		cout << endl;
		return ;
	}
//	cout << "c ->" << static_cast<int>(c) << endl;
	if (!isprint(c))
		cout << "Non displayable";
	else
		cout << c;

	cout << endl;

}

void ScalarConverter::print_int(std::string __unused &arg, ScalarConverter::data_type __unused type) {

	cout << "int: ";
	int i;
	try {
		i = static_cast<int>(std::stoi(arg));
	}
	catch (std::exception &e) {
		if (type == not_a_number)
			cout << "impossible";
		else
			cout << "Not displayable";
		cout << endl;
		return ;
	}
	cout << i;

	cout << endl;
}


void ScalarConverter::print_float(std::string __unused &arg, ScalarConverter::data_type type) {

	float f;

	cout << "float: ";

	try {
		f = static_cast<float>(std::stof(arg));
	}
	catch (std::exception &e) {
		if (type == not_a_number)
			cout << "nan";
		else if (type == plus_infinite)
			cout << "+inf";
		else if (type == neg_infinite)
			cout << "-inf";
		else {
			cout << "Non displayable" << endl;
			return;
		}
		cout << "f" << endl;
		return ;
	}

	cout << f;
	if ((f / std::round(f)) == 1 || !f)
		cout << ".0";
	cout << "f" << endl;
}

void ScalarConverter::print_double(std::string __unused &arg, ScalarConverter::data_type __unused type) {

	double d;

	cout << "double: ";

	try {
		d = static_cast<double>(std::stod(arg));
	}
	catch (std::exception &e) {
		if (type == not_a_number)
			cout << "nan";
		else if (type == plus_infinite)
			cout << "+inf";
		else if (type == neg_infinite)
			cout << "-inf";
		else {
			cout << "Non displayable" << endl;
			return;
		}
	}
	cout << d;
	if ((d / std::round(d) == 1) || !d)
		cout << ".0";
	cout << "d" << endl;

}

void ScalarConverter::converter(std::string &arg) {

	data_type type = parser(arg);
	print_char(arg, type);
	print_int(arg, type);
	print_float(arg, type);
	print_double(arg, type);
}
