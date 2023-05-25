
#include "BitcoinExchange.hpp"

int main(int argc, __unused char **argv)
{
	if (argc != 2)
		return (std::cout << "btc must recieve a input file as argument\n", 0);
	Btc btc;


	try {
		btc.parseData();
		btc.parseInput(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << endl;
		return (1);

	}

}
