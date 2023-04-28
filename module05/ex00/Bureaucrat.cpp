#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(DEFAULT_NAME), _grade(LOWEST_GRADE) {
	cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const string &name, unsigned short grade):_name(name), _grade(grade) {
	if (grade > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	cout << "Bureaucrat named: " << _name << " with grade: " << _grade << " created\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):_name(obj._name), _grade(obj._grade) {
	cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat() {
	cout << "Bureaucrat default destructor called\n";
}

const Bureaucrat Bureaucrat::operator=(const Bureaucrat &obj) {

	(string)_name = (string)obj._name;
	_grade = obj._grade;
	return (*this);
}

std::ostream  &operator<<(std::ostream &os, const Bureaucrat &obj) {
	os << "Bureaucrat " << obj.getName() << ", grade " << obj.getGrade();
	return (os);
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (_grade + 1 < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());

	cout << _name << " grade: " << _grade << " -> " << _grade + 1 << "\n";

	_grade++;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (_grade - 1 < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());

	cout << _name << " grade: " << _grade << " -> " << _grade - 1 << "\n";

	_grade--;

}

unsigned short Bureaucrat::getGrade() const { return(this->_grade); }

const string Bureaucrat::getName() const { return(this->_name); }

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::invalid_argument("grade must be higher than 1") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::invalid_argument("grade must be lower than 150") {}
