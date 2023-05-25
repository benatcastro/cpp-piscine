#include "BitcoinExchange.hpp"


const string Btc::data_file = "data.csv";

Btc::Btc() { cout << "Btc constructed\n"; }

Btc::~Btc() { cout << "Btc destructed\n"; }

void Btc::parseExtension(const std::string file) {

	const string extension(&file.at(file.find_last_of(".")));

	 if (extension.compare(".txt"))
		 throw (std::invalid_argument("invalid file extension\n"));
}

string Btc::checkDate(const std::string date_str) {
	struct tm time;
	cout << "Checking date: " << date_str << endl;
	if (!strptime(date_str.c_str(), "%Y-%m-%d", &time))
		throw (std::invalid_argument("invalid date"));

	if (time.tm_mday == 0)
		throw (std::invalid_argument("invalid date"));
	return date_str;
}

float Btc::checkValue(const std::string value_str) {

	const double d = std::atof(value_str.c_str());

	if (d > std::numeric_limits<int>::max())
		throw (std::invalid_argument("value exceeds max int"));
	if (d < std::numeric_limits<int>::min())
		throw (std::invalid_argument("value lower than min int"));
	return d;

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
		string 		date;
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
				date = checkDate(token);
			if (token && n_tokens == VALUE_TOKEN)
				value = checkValue(token);
			n_tokens++;
			token = std::strtok(NULL, delimiter.c_str());
		}
		while (token);

		if (n_tokens != 2)
			throw (std::invalid_argument("Syntax error"));

		this->_input[date] = value;
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
