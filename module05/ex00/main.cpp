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
	std::cout << "\n\n";
	{
		unsigned short grade = 151;
		try {
			Bureaucrat another("bob", grade);
		}
		catch (const std::exception &e) {
			cerr << "Error creating bureuacrat: " << e.what() << endl;
		}

	}
	std::cout << "\n\n";
	{
		unsigned short grade = 1;
		try {
			Bureaucrat another("patata alavesa", grade);
			another.decrementGrade();
			another.incrementGrade();
			another.incrementGrade();
			another.incrementGrade();
		}
		catch (const std::exception &e) {
			cerr << "Error: " << e.what() << endl;
		}
		std::cout << "\n\n";

	}
	std::cout << "\n\n";
	{
		unsigned short grade = 150;
		try {
			Bureaucrat another("patata vizcaina", grade);
			another.decrementGrade();
		}
		catch (const std::exception &e) {
			cerr << "Error: " << e.what() << endl;
		}
	}
	std::cout << "\n\n";
	{
		unsigned short grade = 20;
		try {
			Bureaucrat another("bob", grade);
			another.incrementGrade();
			another.decrementGrade();
		}
		catch (const std::exception &e) {
			cerr << "Error: " << e.what() << endl;
		}
	}
	std::cout << "\n\n";
	{
		unsigned short grade = -1;
		try {
			Bureaucrat another("bob", grade);
		}
		catch (const std::exception &e) {
			cerr << "Error creating bureuacrat: " << e.what() << endl;
		}
	}
	std::cout << "\n\n";
	cout << "============LEAKS============\n";
    system("leaks -quiet Bureaucrat");
}
