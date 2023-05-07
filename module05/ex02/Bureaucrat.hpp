#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string.h>
# include <iostream>
# include "AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

# define DEFAULT_NAME "Default bureaucrat"


using std::string;
using std::cout;
using std::endl;
using std::cerr;

class AForm;

class Bureaucrat {
private:
    const string	_name;
    unsigned short	_grade; // Grade between 1 - 150 1 -> highest | 150 -> lowest

public:

	class GradeTooLowException: public std::invalid_argument {
	public:
		GradeTooLowException();
	};

	class GradeTooHighException: public std::invalid_argument {
	public:
		GradeTooHighException();
	};

	Bureaucrat(); // Default constructor
	Bureaucrat(const string &name, unsigned short grade); // Grade constructor

	Bureaucrat(const Bureaucrat &obj); // Copy constructor

	~Bureaucrat(); // Default destructor

	Bureaucrat const operator=(Bureaucrat const &obj); // Assigment operator

    void            executeForm(AForm const &form) const;
	bool			signForm(AForm &form);
	static void 	checkGrade(const u_int16_t &grade);
	void			incrementGrade(void);
	void 			decrementGrade(void);
    const string	getName(void) const;
    unsigned short	getGrade(void) const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif

