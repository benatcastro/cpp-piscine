#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <cstring>
# include <iostream>

# define NaN "nan"
# define INF "inf"

using std::cout;
using std::string;
using std::endl;


// A static class is one that cannot be instantiated.
class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();

public:
	enum data_type {
		small_float,
		big_float,
		small_int,
		big_int,
		infinite,
		not_a_number
	};
	static int16_t 		isNonLiteral(string const &arg, string const &nonLiteral);
	static void 		converter(string const &arg);
	static data_type	parser(string const &arg);

};

#endif
