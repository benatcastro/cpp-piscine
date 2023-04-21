#ifndef FORM_HPP
# define FORM_HPP

# include <string.h>
# include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cerr;

# define DEFAULT_NAME "default form"
# define DEFAULT_SIGN_GRADE 1
# define DEFAULT_EXECUTE_GRADE 1

class Form {
private:
	const string 				_name;
	bool 						_signed;
	const unsigned short		_signGrade;
	const unsigned short		_executeGrade;

public:
	Form();
	Form(const Form &obj);
	Form(const string &name, bool isSigned, const unsigned short &signGrade, const unsigned short &executeGrade);

	~Form();

	const Form operator=(const Form &obj);


};

#endif
