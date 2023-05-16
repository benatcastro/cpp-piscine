#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <cstring>
# include <iostream>
# include <cmath>

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
		plus_infinite,
		neg_infinite,
		not_a_number,
		not_found
	};

public:
	static void				print_int(string &arg, data_type type);
	static void				print_double(string &arg, data_type type);
	static void				print_float(string &arg, data_type type);
	static void				print_char(string &arg, data_type type);
	static data_type 		isInf(string &arg);
	static data_type 		isNaN(string &arg);
	static void 			converter(string &arg);
	static data_type		parser(string &arg);

};

#endif
