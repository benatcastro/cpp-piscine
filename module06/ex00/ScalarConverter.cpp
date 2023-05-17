#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { cout << "Scalar converter constructed\n"; }

ScalarConverter::~ScalarConverter() { cout << "Scalar converter destructed\n"; }


ScalarConverter::data_type	ScalarConverter::isNaN(std::string &arg) { return ((arg.compare(NaN) == 0) ? not_a_number : not_found); }

bool ScalarConverter::checkRange(std::string &arg, ScalarConverter::data_type type) {

	long double n;

	n = std::stold(arg);
	switch (type) {
		case character:
			return (n > std::numeric_limits<char>::max() || n < std::numeric_limits<char>::min() ? false : true);
		case double_float:
			return (n > std::numeric_limits<double>::max() || n < std::numeric_limits<double>::lowest() ? false : true);
		case floating_point:
			return (n > std::numeric_limits<float>::max() || n < std::numeric_limits<float>::lowest() ? false : true);
		case integer:
			return (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min() ? false : true);
		default:
			return (false);
	}
}

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

	for (string::iterator it = arg.begin(); it != arg.end(); it++)
		*it = tolower(*it);

	data_type rvalue;

	rvalue = isNaN(arg);
	if (rvalue != not_found)
		return rvalue;
	rvalue = isInf(arg);
	if (rvalue != not_found)
		return rvalue;
	if (isalpha(arg.at(0)) && arg.length() == 1)
		return character;

	return (not_found);
}


void ScalarConverter::print_char(std::string __unused &arg, ScalarConverter::data_type __unused type) {

	char c = {0};

	cout << "char: ";
	try {
		if (!checkRange(arg, character) && type != plus_infinite && type != neg_infinite) {
			cout << "impossible";
			goto end;
		}
		else if (type == character)
			c = static_cast<int>(arg.at(0));
		else
			c = static_cast<char>(std::stoi(arg));
	}
	catch (std::exception &e) {
		cout << "impossible";
		goto end;
	}

	if (!isprint(c))
		cout << "Not displayable";
	else
		cout << c;
	end:
		cout << endl;

}

void ScalarConverter::print_int(std::string __unused &arg, ScalarConverter::data_type __unused type) {

	int i = {0};

	cout << "int: ";

	try {
		if (!checkRange(arg, integer) && type != plus_infinite && type != neg_infinite) {
			cout << "impossible";
			goto end;
		}
		if (type == character)
			i = static_cast<int>(arg.at(0));
		else
			i = static_cast<int>(std::stoi(arg));
	}
	catch (std::exception &e) {
		cout << "impossible";
		goto end;
	}
	cout << i;

	end:
	cout << endl;
}

void ScalarConverter::print_float(std::string __unused &arg, ScalarConverter::data_type type) {

	float f = {0};

	cout << "float: ";

	try {
		if (!checkRange(arg, floating_point) && type != plus_infinite && type != neg_infinite) {
			cout << "impossible";
			goto end;
		}
		if (type == character)
			f = static_cast<float>(arg.at(0));
		else
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
			cout << "impossible ";
		}
		goto end;
	}

	cout << f;
	if ((f / std::round(f)) == 1 || !f)
		cout << ".0";
	end:
		cout << "f" << endl;
}

void ScalarConverter::print_double(std::string __unused &arg, ScalarConverter::data_type __unused type) {

	double d = {0};

	cout << "double: ";

	try {
		if (!checkRange(arg, double_float) && type != plus_infinite && type != neg_infinite) {
			cout << "impossible";
			goto end;
		}
		if (type == character)
			d = static_cast<double>(arg.at(0));
		else
			d = static_cast<double>(std::stod(arg));
	}
	catch (std::exception &e) {
		if (type == not_a_number)
			cout << "nan";
		else if (type == plus_infinite)
			cout << "+inf";
		else if (type == neg_infinite)
			cout << "-inf";
		else
			cout << "Impossible ";
		goto end;
	}
	cout << d;
	if ((d / std::round(d) == 1) || !d)
		cout << ".0";
	end:
	cout << "d" << endl;

}

void ScalarConverter::converter(std::string &arg) {

	data_type type = parser(arg);
	print_char(arg, type);
	print_int(arg, type);
	print_float(arg, type);
	print_double(arg, type);
}
