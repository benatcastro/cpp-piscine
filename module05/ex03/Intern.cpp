#include "Intern.hpp"



Intern::Intern() { cout << "Intern constructed\n"; }

Intern::Intern(const Intern __unused &obj) { cout << "Intern copy constructor called\n"; }
Intern::~Intern() { cout << "Intern destructed\n"; }

Intern &Intern::operator=(const Intern __unused &obj) { return (*this); }

Intern::NoMatchException::NoMatchException(const std::string error): std::runtime_error(error) {}

AForm *Intern::createRRF(const std::string target) { return  new RobotomyRequestForm(target); }

AForm *Intern::createSCF(const std::string target) { return new ShruberryCreationForm(target); }

AForm *Intern::createPPF(const std::string target) { return new PresidentialPardonForm(target); }

int Intern::getFormIndex(const std::string formName) {
	const string formNames[] = {
			"RobotomyRequestForm",
			"ShruberryCreationForm",
			"PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
		if (formName == formNames[i])
			return (i);
	throw (NoMatchException("No match for: " + formName));
}

AForm *Intern::makeForm(const std::string formName, const std::string formTarget) {
	int idx;

	AForm* (Intern::*createForm[])(const std::string) = {
			&Intern::createRRF,
			&Intern::createSCF,
			&Intern::createPPF};
	idx = getFormIndex(formName);

	return (this->*createForm[idx])(formTarget);

}
