#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <limits>

# define DATE_TOKEN 0
# define VALUE_TOKEN 1

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Btc {
public:
	Btc();
	Btc(Btc const &rhs);
	~Btc();

	Btc operator=(Btc const &rhs);

	void	parseData(void);
	void	parseInput(string inputFile);
	void 	compare(string date, float n_btc);

private:
	void 	parseExtension(const string file);
	string 	checkDate(const string date_str);
	float 	checkValue(const double value);
	bool 	isFloat(const string str);

private:
	std::map<string, float> _data;

private:
	static const string data_file;

};


#endif
