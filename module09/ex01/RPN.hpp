#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include "string"
# include <stack>

# define VERBOSE 0

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class RPN {
public:
	RPN();
	~RPN();
	RPN(RPN const &rhs);

	RPN &operator=(RPN const &rhs);

	void				checkArg(char **argv);
	void				checkArg(char *argv);
	static bool 		isSet(const string str, string const set);
private:
	void 				validateToken(const string token);
	void 				calculate(char operation);
	std::stack<int>		numbers;


};

#endif
