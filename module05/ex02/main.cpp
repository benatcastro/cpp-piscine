#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {

	{
		RobotomyRequestForm rrq("paco");
		Bureaucrat executor("bob", 46);

        rrq.beSigned(executor);
        executor.executeForm(rrq);
		try {
			executor.executeForm(rrq);
//            rrq.execute(executor);
		}
		catch (std::exception &e) {
			cout << "Exception: " <<  e.what() << endl;
		}
	}

	cout << "\n\n============LEAKS============\n";
    system("leaks -quiet ex02");
}
