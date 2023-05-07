#ifndef SHRUBERRY_CREATION_FORM_HPP
# define SHRUBERRY_CREATION_FORM_HPP

# include "AForm.hpp"

# define SIGN_GRADE 145
# define EXEC_GRADE 137

class ShruberryCreationForm: public AForm {

private:
    string const _target;

public:
    ShruberryCreationForm();
    ShruberryCreationForm(string const &target);
    ShruberryCreationForm(ShruberryCreationForm const &obj);
    ~ShruberryCreationForm();

    ShruberryCreationForm &operator=(ShruberryCreationForm const &obj);

    void execute(const Bureaucrat &executor) const;


};

#endif
