#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {


    ShruberryCreationForm scf;
    Bureaucrat executor("test", 20);

    executor.signForm(scf);
    scf.execute(executor);


	cout << "============LEAKS============\n";
    system("leaks -quiet ex02");
}
