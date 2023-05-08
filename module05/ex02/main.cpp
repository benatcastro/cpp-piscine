#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {


    ShruberryCreationForm scf;
    Bureaucrat executor("test", 20);

//    executor.signForm(scf);
//	cout << scf << endl;
//    scf.execute(executor);

	try {

		executor.executeForm(scf);
	}
	catch (std::exception &e) {
		cout << "Error: " << e.what()  << endl;
	}

	cout << "\n\n============LEAKS============\n";
    system("leaks -quiet ex02");
}
