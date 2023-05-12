#ifndef PRESIDENTAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {
private:
	static const u_int8_t _sign_grade = 25;
	static const u_int8_t _exec_grade = 5;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &obj);
	PresidentialPardonForm(string const &target);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);

	void execute(const Bureaucrat &executor) const;
};

#endif
#include "AForm.hpp"
