#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {

	{
		RobotomyRequestForm rrq("paco");
		Bureaucrat executor("bob", 20);

		try {
			rrq.beSigned(executor);
			executor.executeForm(rrq);
		}
		catch (std::exception &e) {
			cout << "Error: " <<  e.what() << endl;
		}
	}

	cout << "\n\n============LEAKS============\n";
    system("leaks -quiet ex02");
}
