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

void Bureaucrat::executeForm(AForm const &form) const {

    if (!Bureaucrat::canExecute(form))
        return;
	cout << *this << " executed " << form << endl;
	form.execute(*this);

}

bool Bureaucrat::signForm(AForm &form) {
	if (!Bureaucrat::canSign(form))
		return (false);
	return (form.beSigned(*this));
}

bool Bureaucrat::canSign(const AForm &form) const {
	if (form.getSignGrade() < this->_grade)
		return (cout << this->_name << " cant't sign form: " << form.getName() << " because his grade is too low\n", false);
	return (true);

}

bool Bureaucrat::canExecute(AForm const &form) const {
    if (form.getSign() == false)
        return (cout << this->_name << " can't execute form: " << form.getName() << " because is not signed\n", false);
    if (form.getExecuteGrade() < this->_grade)
        return (cout << this->_name << " cat't execute form: " << form.getName() << " because his grade is too low\n", false);
    return (true);
}

unsigned short Bureaucrat::getGrade() const { return(this->_grade); }

const string Bureaucrat::getName() const { return(this->_name); }

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::invalid_argument("grade must be higher") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::invalid_argument("grade must be lower") {}
