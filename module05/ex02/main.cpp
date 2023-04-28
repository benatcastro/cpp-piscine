#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {


	cout << "============LEAKS============\n";
    system("leaks -quiet Bureaucrat");
}
