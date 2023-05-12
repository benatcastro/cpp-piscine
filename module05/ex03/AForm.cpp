#include "AForm.hpp"
#include "Bureaucrat.hpp"




// Default constructor
AForm::AForm():_target("DEFAULT TARGT"), _name(DEFAULT_FORM_NAME), _signed(false), _signGrade(DEFAULT_SIGN_GRADE), _executeGrade(DEFAULT_EXECUTE_GRADE) {

	cout << "Default form constructor called\n";
}

AForm::AForm(const AForm &obj):_target(obj._target), _name(obj._name),  _signed(obj._signed), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {

	cout << "Form copy constructor called\n";
}

AForm::AForm(
		const std::string &name, const unsigned short &signGrade, const unsigned short &executeGrade, string target
		):_target(target), _name(name),_signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {

	AForm::checkGrade(_signGrade);
	AForm::checkGrade(_executeGrade);

	cout	<< "Form created with name: " << _name
			<< " signed: " << _signed
			<< " sign grade: " << _signGrade
			<< " execute grade: " << _executeGrade
			<< endl;

}


//AForm::~AForm() {
//	cout << "Form default destructor called\n";
//}

bool AForm::canExecute(const Bureaucrat &executor) const {

    if (!this->_signed) {

        throw (AForm::CantExecuteException());
    }
   if (executor.getGrade() > this->_executeGrade) {

       throw (AForm::CantExecuteException());
   }

   return (true);

}

void AForm::checkGrade(const u_int16_t grade) {
	if (grade > LOWEST_GRADE)
		throw (AForm::GradeTooHighException());
	if (grade < HIGHEST_GRADE)
		throw (AForm::GradeTooLowException());

}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {

	os		<< "Form name: " << obj.getName()
			<< " signed: " << obj.getSign()
			<< " sign grade: " << obj.getSignGrade()
			<< " execute grade: " << obj.getExecuteGrade();
	return (os);
}

bool AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
        throw (AForm::GradeTooLowException());
    }
	if (bureaucrat.getGrade() <= _signGrade) {

        _signed = true;
		cout << bureaucrat << " signed form -> " << *this << endl;
	}

	return (_signed);
}


AForm::GradeTooHighException::GradeTooHighException(): std::invalid_argument("Form || grade must be lower") {}

AForm::GradeTooLowException::GradeTooLowException(): std::invalid_argument("Form || grade must be higher") {}

AForm::CantExecuteException::CantExecuteException(): std::invalid_argument("form cannot be executed, not signed or bureaucrat doesnt have enough grade") {}

string AForm::getName() const { return (_name); }

u_int16_t AForm::getExecuteGrade() const { return (_executeGrade); }

bool AForm::getSign() const {return (_signed); }

u_int16_t AForm::getSignGrade() const { return (_signGrade); }
