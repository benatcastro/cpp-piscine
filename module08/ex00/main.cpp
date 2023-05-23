#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <list>

int main(void)
{

	{
		std::cout << "\n\n****VECTOR TEST****\n\n";
		int int_tab[] = {0, 1, 2, 3, 4, 5};
		std::vector<int> int_vector(int_tab, int_tab + sizeof(int_tab) / sizeof(*int_tab));

		try {
			std::cout << *easyfind(int_vector, 5) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}


		std::cout << "\n\n****LIST TEST****\n\n";

		std::list<int> int_list;
		int_list.push_back(1);
		int_list.push_back(2);
		int_list.push_back(3);

		try {
			std::cout << *easyfind(int_list, 2) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n\n****SET TEST****\n\n";

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
