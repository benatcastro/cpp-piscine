#ifndef AFORM_HPP
# define AFORM_HPP


# include "Bureaucrat.hpp"
# include <string.h>
# include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cerr;

# define DEFAULT_FORM_NAME "default form"
# define DEFAULT_SIGN_GRADE 1
# define DEFAULT_EXECUTE_GRADE 1

class Bureaucrat;

class AForm {
private:
	const string 				_name;
	bool 						_signed;
	const unsigned short		_signGrade;
	const unsigned short		_executeGrade;

public:
	AForm();
	AForm(const AForm &obj);
	AForm(const string &name, bool isSigned, const unsigned short &signGrade, const unsigned short &executeGrade);

	~AForm();

	const AForm operator=(const AForm &obj);

	bool			canExecute(const Bureaucrat &bureaucrat) const;
	bool			canExecute(const u_int16_t &grade) const;
	bool			canSign(const Bureaucrat &bureaucrat) const;
	bool			canSign(const u_int16_t &grade) const;
	virtual void	execute(Bureaucrat const &executor) const = 0;
	string			getName(void) const;
	bool			getSign(void) const;
	u_int16_t 		getSignGrade(void) const;
	u_int16_t		getExecuteGrade(void) const;

	class GradeTooLowException: public std::invalid_argument {
	public:
		GradeTooLowException();
	};

	class GradeTooHighException: public std::invalid_argument {
	public:
		GradeTooHighException();
	};

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
