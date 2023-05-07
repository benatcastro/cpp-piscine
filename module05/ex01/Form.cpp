#include "Form.hpp"
#include "Bureaucrat.hpp"




// Default constructor
Form::Form():_name(DEFAULT_FORM_NAME), _signed(false), _signGrade(DEFAULT_SIGN_GRADE), _executeGrade(DEFAULT_EXECUTE_GRADE) {

	cout << "Default form constructor called\n";
}

Form::Form(const Form &obj):_name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {

	cout << "Form copy constructor called\n";
}

Form::Form(
		const std::string &name, const unsigned short &signGrade, const unsigned short &executeGrade
		):_name(name),_signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {

	Form::checkGrade(_signGrade);
	Form::checkGrade(_executeGrade);

	cout	<< "Form created with name: " << _name
			<< " signed: " << _signed
			<< " sign grade: " << _signGrade
			<< " execute grade: " << _executeGrade
			<< endl;

}

const Form Form::operator=(const Form &obj) {

	cout << "Form assignment operator called\n";

	_signed = obj._signed;

	return (*this);
}

Form::~Form() {
	cout << "Form default destructor called\n";
}

void Form::checkGrade(const u_int16_t grade) {
	if (grade > LOWEST_GRADE)
		throw (Form::GradeTooHighException());
	if (grade < HIGHEST_GRADE)
		throw (Form::GradeTooLowException());

}

std::ostream& operator<<(std::ostream& os, const Form& obj) {

	os		<< "Form name: " << obj.getName()
			<< " signed: " << obj.getSign()
			<< " sign grade: " << obj.getSignGrade()
			<< " execute grade: " << obj.getExecuteGrade();
	return (os);
}

bool Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
        throw (Form::GradeTooLowException());
    }
	if (bureaucrat.getGrade() <= _signGrade) {

		cout << bureaucrat << " signed form -> ";
		_signed = true;
        cout << *this;
	}

	return (_signed);
}

Form::GradeTooHighException::GradeTooHighException(): std::invalid_argument("Form || grade must be lower") {}

Form::GradeTooLowException::GradeTooLowException(): std::invalid_argument("Form || grade must be higher") {}

string Form::getName() const { return (_name); }

u_int16_t Form::getExecuteGrade() const { return (_executeGrade); }

bool Form::getSign() const {return (_signed); }

u_int16_t Form::getSignGrade() const { return (_signGrade); }
