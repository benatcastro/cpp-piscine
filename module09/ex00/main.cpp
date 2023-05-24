
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "btc must recieve a input file as argument\n", 0);
	Btc btc;

	btc.parseInput();
}
