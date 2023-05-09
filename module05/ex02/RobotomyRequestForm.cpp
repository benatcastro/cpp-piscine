#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
		AForm("Robotomy Request form", RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade, "DEFAULT_TARGET")  {

	cout << "Robotomoy Request form constructed with default target\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
		AForm("Robotomy Request form", RobotomyRequestForm::_sign_grade, RobotomyRequestForm::_exec_grade, target)
{
	cout << "Robotomy request form constructed with target: " + target + "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):
	AForm(obj._name, obj._signGrade, obj._executeGrade, obj._target) {
	cout << "Robotomy request form copied\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	this->_name = obj._name;
	this->_target = obj._target;

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << "Robotomy request form destructed\n";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	canExecute(executor);

	cout << "Drilling noises....\n";
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		cout << _target << " robotomized succesfully!\n";
	else
		cout << "Upsi!, almost robotomized!\n";

}
