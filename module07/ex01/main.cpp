#include "Iter.hpp"
#include <string.h>

/*
class Awesome {
public:
	Awesome(void): _n(42) {return;};
	int get(void) const {return this->_n; }
private:
	int _n;
};

std::ostream & operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get(); return o;}
*/

int main(void)
{
	{
		std::cout << "Array of integers\n";
		const int int_tab[] = {1, 2, 3, 4};

		iter(int_tab, 4, &print);

		std::cout << "Array of doubles\n";
		const double double_tab[] = {1.2, 2.3, 3.4, 4.5};

		iter(double_tab, 4, print);

		std::cout << "Array of strings\n";
		const std::string str_tab[] = {"hola", "adios", "str1", "str2"};

		iter(str_tab, 4, print);

	/*
		std::cout << "Array of Awesome\n";
		const Awesome awesome_tab[5];

		iter(awesome_tab, 5, print);
	 */
	}
	system("leaks --quiet Iter");

 }

