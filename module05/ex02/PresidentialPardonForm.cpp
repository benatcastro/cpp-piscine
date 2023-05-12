#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidental Pardon form",PresidentialPardonForm::_sign_grade, PresidentialPardonForm::_exec_grade, "DEFAULT_TARGET")  {

		cout << "Presidential pardon request constructed with default target\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
		AForm("Presidental Pardon form",PresidentialPardonForm::_sign_grade, PresidentialPardonForm::_exec_grade, target)  {

	cout << "Presidential pardon request constructed with target: " + target + "\n";

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):
	AForm(obj._name, obj._signGrade, obj._executeGrade, obj._target) {
	cout << "Presidential pardon form copied\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	cout << "Presidential Pardon Form destructed\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    (string)this->_target = (string)obj._target;
    (string)this->_name = (string)obj._name;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	canExecute(executor);

	cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
