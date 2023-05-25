#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;
	if (argc != 2)
		return (cout << "argc error\n", EXIT_FAILURE);
	try {
		rpn.checkArg(argv[1]);

	}
	catch (std::exception &e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}
