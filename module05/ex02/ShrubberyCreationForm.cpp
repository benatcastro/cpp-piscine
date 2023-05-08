#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShruberryCreationForm::ShruberryCreationForm():
        AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE), _target("DEFAULT TARGET") {
   cout << "Shruberry creation form constructed with default target\n";

}

ShruberryCreationForm::ShruberryCreationForm(string const &target):
        AForm("Shruberry Creation Form", SIGN_GRADE, EXEC_GRADE), _target(target) {
    cout << "Shruberry creation form constructed with target: " + target + "\n";

}

ShruberryCreationForm::~ShruberryCreationForm() {
    cout << "Shruberry creation form destructed\n";
}

void ShruberryCreationForm::execute(const Bureaucrat &executor) const {
    canExecute(executor);

    std::ofstream outfile(_target + "_shruberry");

     outfile << "ASCII trees\n"<<
                "                                 # #### ####\n"
                "                                ### \\/#|### |/####\n"
                "                               ##\\/#/ \\||/##/_/##/_#\n"
                "                             ###  \\/###|/ \\/ # ###\n"
                "                           ##_\\_#\\_\\## | #/###_/_####\n"
                "                          ## #### # \\ #| /  #### ##/##\n"
                "                           __#_--###`  |{,###---###-~\n"
                "                                     \\ }{\n"
                "                                      }}{\n"
                "                                      }}{\n"
                "                                 ejm  {{}\n"
                "                                , -=-~{ .-^- _\n"
                "                                      `}\n"
                "                                       {\n"
                "\n"
                "";

}

ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm __unused &obj) {
    return *this;
}
