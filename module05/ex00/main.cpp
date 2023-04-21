#include "Bureaucrat.hpp"

int main(void) {
	{
		Bureaucrat def;
		Bureaucrat another("bob", 0);

		cout << another << "\n";
		def = another;
		cout << "after copy\n";
		cout << def << "\n";

	}
	cout << "============LEAKS============\n";
    system("leaks -quiet Bureaucrat");
}
