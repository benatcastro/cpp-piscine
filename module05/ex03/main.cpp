#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
	{
		Intern intern;
		try {
			AForm *rrf = intern.makeForm("RobotomyRequestForm", "default target");
			AForm *ppf = intern.makeForm("PresidentialPardonForm", "default target");
			AForm *scf = intern.makeForm("ShruberryCreationForm", "default target");
			delete rrf;
			delete ppf;
			delete scf;
			intern.makeForm("patata","patata");
		}
		catch (std::exception &e) {
			cout << "Exception: " <<  e.what() << endl;
		}
	}


	cout << "\n\n============LEAKS============\n";
    system("leaks -quiet ex02");
}
