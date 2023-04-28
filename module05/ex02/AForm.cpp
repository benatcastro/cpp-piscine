#include "AForm.hpp"
#include "Bureaucrat.hpp"




// Default constructor
AForm::AForm():_name(DEFAULT_FORM_NAME), _signed(false), _signGrade(DEFAULT_SIGN_GRADE), _executeGrade(DEFAULT_EXECUTE_GRADE) {

	cout << "Default form constructor called\n";
}

AForm::AForm(const AForm &obj):_name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {

	cout << "Form copy constructor called\n";
}

AForm::AForm(
		const std::string &name, bool isSigned, const unsigned short &signGrade, const unsigned short &executeGrade
		):_name(name),_signed(isSigned), _signGrade(signGrade), _executeGrade(executeGrade) {

	cout	<< "Form created with name: " << _name
			<< " signed: " << _signed
			<< " sign grade: " << _signGrade
			<< " execute grade: " << _executeGrade
			<< endl;

}

const AForm AForm::operator=(const AForm &obj) {

	cout << "Form assignment operator called\n";

	_signed = obj._signed;

	return (*this);
}

AForm::~AForm() {
	cout << "Form default destructor called\n";
}

//void AForm::checkGrade(const u_int16_t grade) {
//	if (grade > LOWEST_GRADE)
//		throw (Form::GradeTooHighException());
//	if (grade < HIGHEST_GRADE)
//		throw (Form::GradeTooLowException());
//
//}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {

	os		<< "Form name: " << obj.getName()
			<< " signed: " << obj.getSign()
			<< " sign grade: " << obj.getSignGrade()
			<< " execute grade: " << obj.getExecuteGrade()
			<< endl;
	return (os);
}

//bool AForm::beSigned(const Bureaucrat &bureaucrat) {
//	if (bureaucrat.getGrade() > _signGrade)
//		throw (Form::GradeTooLowException());
//	if (bureaucrat.getGrade() <= _signGrade) {
//
//		cout << bureaucrat << " signed " << *this;
//		_signed = true;
//		return (_signed);
//	}
//
//	cout << bureaucrat << " can't sign " << *this;
//	return (_signed);
//}

AForm::GradeTooHighException::GradeTooHighException(): std::invalid_argument("Form || grade must be lower") {}

AForm::GradeTooLowException::GradeTooLowException(): std::invalid_argument("Form || grade must be higher") {}

string AForm::getName() const { return (_name); }

u_int16_t AForm::getExecuteGrade() const { return (_executeGrade); }

bool AForm::getSign() const {return (_signed); }

u_int16_t AForm::getSignGrade() const { return (_signGrade); }
