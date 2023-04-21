#include "Bureaucrat.hpp"

int main(void) {
	{
		unsigned short grade = 0;
		try {
			Bureaucrat another("bob", grade);
		}
		catch (const std::exception &e) {
			cerr << "Error creating bureuacrat: " << e.what() << endl;
		}

	}
	{
		unsigned short grade = 151;
		try {
			Bureaucrat another("bob", grade);
		}
		catch (const std::exception &e) {
			cerr << "Error creating bureuacrat: " << e.what() << endl;
		}

	}
	{
		unsigned short grade = 20;
		try {
			Bureaucrat another("bob", grade);
		}
		catch (const std::exception &e) {
			cerr << "Error creating bureuacrat: " << e.what() << endl;
		}

	}
	{
		unsigned short grade = -1;
		try {
			Bureaucrat another("bob", grade);
		}
		catch (const std::exception &e) {
			cerr << "Error creating bureuacrat: " << e.what() << endl;
		}

	}
	cout << "============LEAKS============\n";
    system("leaks -quiet Bureaucrat");
}
