#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	const string formNames[3];

public:
	Intern();
	~Intern();
	Intern(Intern const &obj);
	Intern &operator=(Intern const &obj);


	int		getFormIndex(string const formName);
	AForm 	*makeForm(string const formName, string const formTarget) ;
	AForm 	*createRRF(string const target);
	AForm 	*createPPF(string const target);
	AForm 	*createSCF(string const target);

	class NoMatchException: public std::runtime_error {
	public:
		NoMatchException(string const error);
	};

};


#endif
