#include "BitcoinExchange.hpp"


const string Btc::data_file = "data.csv";

Btc::Btc() { cout << "Btc constructed\n"; }

Btc::~Btc() { cout << "Btc destructed\n"; }

Btc::Btc(const Btc &rhs) { this->_data = rhs._data; }

Btc Btc::operator=(const Btc &rhs) { this->_data = rhs._data; }

bool Btc::isFloat(const std::string str) {

	char *end;

	std::strtod(str.c_str(), &end);
	if (end == str.c_str() || *end != '\0')
		throw (std::range_error("invalid syntax"));
	return true;
}

void Btc::compare(string date, float n_btc) {

	std::map<string, float>::iterator lb = this->_data.lower_bound(date);
	cout << date << " => " << n_btc << " = " << lb->second * n_btc << endl;

}

void Btc::parseExtension(const std::string file) {

	const string extension(&file.at(file.find_last_of(".")));

	 if (extension.compare(".txt"))
		 throw (std::invalid_argument("invalid file extension\n"));
}

string Btc::checkDate(const std::string date_str) {
	struct tm time;

	if (!strptime(date_str.c_str(), "%Y-%m-%d", &time))
		throw (std::range_error("invalid date"));

	if (time.tm_mday == 0)
		throw (std::range_error("invalid date"));
	return date_str;
}

float Btc::checkValue(const double value) {

	if (value < 0)
		throw (std::invalid_argument("not a positive number"));
	if (value > 1000)
		 throw (std::invalid_argument("number is too big"));
	return value;

}

void Btc::parseInput(string file) {

	std::ifstream inputFile;
	string line;
	const string delimiter = " |";


	this->parseExtension(file);

	inputFile.open(file);
	if (!inputFile)
		throw (std::runtime_error("Can't open file"));

	do {
		u_int32_t	n_tokens = 0;
		string 		date, s_value;
		char 		*token;
		float		value;

		std::getline(inputFile, line);

		if (!line.compare("date | value"))
			continue;
		if (line.empty())
			return;

		token = std::strtok((char *)line.c_str(), delimiter.c_str());
		do {
			if (token && n_tokens == DATE_TOKEN)
				date = token;
			if (token && n_tokens == VALUE_TOKEN)
			{
				s_value = token;
				value = std::atof(token);
			}
			n_tokens++;
			token = std::strtok(NULL, delimiter.c_str());
		}
		while (token);
		if (n_tokens != 2)
		{
			cerr << "Error: bad input => " << line << endl;
			continue;
		}
		try
		{
			checkDate(date);
			isFloat(s_value);
			checkValue(value);
		}
		catch (std::range_error &e)
		{
			cerr << "Error: bad input => " << line << endl;
		}
		catch (std::exception &e)
		{
			cerr << "Error: " << e.what() << endl;
		}
		Btc::compare(date, value);
	} while (!inputFile.eof());

	inputFile.close();
}

void Btc::parseData(void) {

	std::ifstream inFile;
	string line;

	inFile.open(Btc::data_file);

	if (!inFile)
		throw (std::runtime_error("Can't open file"));

	do {
		std::getline(inFile, line);
		if (line.empty())
			break;
		string date(std::strtok((char *)line.c_str(), ","));
		string value(std::strtok(NULL, ","));
		this->_data[date] = std::atof(value.c_str());
	} while (!inFile.eof());

	inFile.close();
}
