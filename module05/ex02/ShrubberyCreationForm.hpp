#ifndef SHRUBERRY_CREATION_FORM_HPP
# define SHRUBERRY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShruberryCreationForm: public AForm {
private:
	static const u_int8_t _sign_grade = 145;
	static const u_int8_t _exec_grade = 137;

public:
    ShruberryCreationForm();
    ShruberryCreationForm(string const &target);
    ShruberryCreationForm(ShruberryCreationForm const &obj);
    ~ShruberryCreationForm();

    ShruberryCreationForm &operator=(ShruberryCreationForm const &obj);

    void execute(const Bureaucrat &executor) const;


};

#endif
