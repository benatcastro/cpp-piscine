#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(DEFAULT_NAME), _grade(LOWEST_GRADE) {
	cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const string &name, unsigned short grade):_name(name), _grade(grade) {
	checkGrade(grade);
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

void Bureaucrat::checkGrade(const u_int16_t &grade) {
	if (grade > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
}


void Bureaucrat::decrementGrade() {

	checkGrade(_grade + 1);

	cout << _name << " grade: " << _grade << " -> " << _grade + 1 << "\n";

	_grade++;
}

void Bureaucrat::incrementGrade() {
	checkGrade(_grade - 1);

	cout << _name << " grade: " << _grade << " -> " << _grade - 1 << "\n";

	_grade--;

}

bool Bureaucrat::signForm(AForm &form) {
    if (this->_grade > form.getSignGrade()) {
        cout << *this << " couldn't sign " << form << " because bureaucrat's grade is not enough\n";
        throw (Bureaucrat::GradeTooLowException());
    }
	return (form.beSigned(*this));
}

unsigned short Bureaucrat::getGrade() const { return(this->_grade); }

const string Bureaucrat::getName() const { return(this->_name); }

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::invalid_argument("grade must be higher than 1") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::invalid_argument("grade must be lower than 150") {}
