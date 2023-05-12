#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
private:
	static const u_int8_t _sign_grade = 72;
	static const u_int8_t _exec_grade = 45;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(string const &target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);

	void execute(const Bureaucrat &executor) const;

};

#endif
