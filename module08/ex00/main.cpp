#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <set>

int main(void)
{

	{
		int int_tab[] = {0, 1, 2, 3, 4, 5};
		std::vector<int> int_vector(int_tab, int_tab + sizeof(int_tab) / sizeof(*int_tab));

		try {
			std::cout << *easyfind(int_vector, 5) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}


		std::array<int, 3> int_array;

		int_array[0] = 0;
		int_array[1] = 1;
		int_array[2] = 2;

		try {
			std::cout << *easyfind(int_array, 2) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}


		std::set<int> int_set;

		for (int i = 0; i < 10; i++)
			int_set.insert(i);

		try {
			std::cout << *easyfind(int_set, 11) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

	}

	std::cout << "=====LEAKS=====\n";
	system("leaks --quiet easyfind");


}
