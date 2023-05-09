#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
		AForm("Robotomy Request form", RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade, "DEFAULT_TARGET")  {

	cout << "Robotomoy Request form constructed with default target\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
		AForm("Robotomy Request form", RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade, target)
{
	cout << "Robotomy request form constructed with target: " + target + "\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << "Robotomy request form destructed\n";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	canExecute(executor);

	cout << "Drilling noises....\n";
	cout << rand();
	if (!rand() % 2)
		cout << _target << " robotomized succesfully!\n";
	else
		cout << "Upsi!, almost robotomized!\n";

}
