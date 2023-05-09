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
protected:
	const string				_target;
	const string 				_name;
	bool 						_signed;
	const unsigned short		_signGrade;
	const unsigned short		_executeGrade;

public:
	AForm();
	AForm(const AForm &obj);
	AForm(const string &name, const unsigned short &signGrade, const unsigned short &executeGrade, string target);

	~AForm();

//	virtual AForm& operator=(const AForm &obj) = 0;

    bool            canExecute(Bureaucrat const &executor) const;
    virtual void    execute(Bureaucrat const &executor) const = 0;
	void 		    checkGrade(const u_int16_t grade);
	bool		    beSigned(const Bureaucrat &bureaucrat);
	string		    getName(void) const;
	bool		    getSign(void) const;
	u_int16_t 	    getSignGrade(void) const;
	u_int16_t	    getExecuteGrade(void) const;

class GradeTooLowException: public std::invalid_argument {
public:
    GradeTooLowException();
};

class GradeTooHighException: public std::invalid_argument {
public:
    GradeTooHighException();
};

class CantExecuteException: public std::invalid_argument {
public:
    CantExecuteException();
};

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
