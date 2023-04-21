#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name(DEFAULT_NAME), _grade(LOWEST_GRADE) {
	cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(string name, unsigned short grade):_name(name), _grade(grade) {
	try {
		if (grade < LOWEST_GRADE)
			throw (Bureaucrat::GradeTooLowException());
//		if (grade > HIGHEST_GRADE)
//			throw (Bureaucrat::GradeTooHighException("high"));
	}
	catch (const std::exception &e) {
		cerr << "Error creating bureacrat: " << e.what() << endl;
	}
	cout << "Bureaucrat named: " << _name << " with grade: " << _grade << " created\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):_name(obj._name), _grade(obj._grade) {
	cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat() {
	cout << "Bureaucrat default destructor called\n";
}

const Bureaucrat Bureaucrat::operator=(const Bureaucrat &obj) {

	this->_grade = obj._grade;
	return (*this);
}

std::ostream  &operator<<(std::ostream &os, const Bureaucrat &obj) {
	os << "Bureaucrat " << obj.getName() << ", grade " << obj.getGrade();
	return (os);
}

unsigned short Bureaucrat::getGrade() const { return(this->_grade); }

const string Bureaucrat::getName() const { return(this->_name); }

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::invalid_argument("grade must be higher than 1") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::invalid_argument("Grade must be lower than 150") {}
