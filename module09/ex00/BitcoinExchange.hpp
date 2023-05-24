#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <map>

using std::cout;
using std::endl;
using std::string;

class Btc {
public:
	Btc();
	Btc(Btc const &rhs);
	~Btc();

	void	parseInput(string const file);
	Btc operator=(Btc const &rhs);

private:
	std::map<string, int> _data;


};


#endif
