#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form():_name(DEFAULT_NAME), _signed(false), _signGrade(DEFAULT_SIGN_GRADE), _executeGrade(DEFAULT_EXECUTE_GRADE) {
	cout << "Default form constructor called\n";
	if (_executeGrade > LOWEST_GRADE || _signGrade > LOWEST_GRADE) throw (Bureaucrat::GradeTooHighException());
	if (_executeGrade < HIGHEST_GRADE || _signGrade < HIGHEST_GRADE) throw (Bureaucrat::GradeTooLowException());
}

Form::Form(const Form &obj):_name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {
	cout << "Form copy constructor called\n";
	if (grade > LOWEST_GRADE) throw (Bureaucrat::GradeTooHighException());
	if (grade < HIGHEST_GRADE) throw (Bureaucrat::GradeTooLowException());
}

Form::Form(
		const std::string &name, bool isSigned, const unsigned short &signGrade, const unsigned short &executeGrade
		):_name(name),_signed(isSigned), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (_executeGrade > LOWEST_GRADE || _signGrade > LOWEST_GRADE) throw (Bureaucrat::GradeTooHighException());
	if (_executeGrade < HIGHEST_GRADE || _signGrade < HIGHEST_GRADE) throw (Bureaucrat::GradeTooLowException());


}
