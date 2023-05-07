#ifndef FORM_HPP
# define FORM_HPP


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

class Form {
private:
	const string 				_name;
	bool 						_signed;
	const unsigned short		_signGrade;
	const unsigned short		_executeGrade;

public:
	Form();
	Form(const Form &obj);
	Form(const string &name, const unsigned short &signGrade, const unsigned short &executeGrade);

	~Form();

	const Form operator=(const Form &obj);

	void 		checkGrade(const u_int16_t grade);
	bool		beSigned(const Bureaucrat &bureaucrat);
	string		getName(void) const;
	bool		getSign(void) const;
	u_int16_t 	getSignGrade(void) const;
	u_int16_t	getExecuteGrade(void) const;

	class GradeTooLowException: public std::invalid_argument {
	public:
		GradeTooLowException();
	};

	class GradeTooHighException: public std::invalid_argument {
	public:
		GradeTooHighException();
	};

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
