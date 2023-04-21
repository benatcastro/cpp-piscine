#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <cstring>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat {
private:
    const string	_name;
    unsigned short	_grade; // Grade between 1 - 150 1 -> highest | 150 -> lowest
public:
	Bureaucrat(); // Default constructor
	Bureaucrat(unsigned short grade); // Grade constructor



    const string	getName(void) const;
    unsigned short	getGrade(void) const;

};

#endif

