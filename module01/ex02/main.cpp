#include <string.h>
#include <iostream>

int main (void) {
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "////Mem adresses////" << std::endl;
	std::cout << "Str adress: " << &str << std::endl;
	std::cout << "Ptr adress: " << stringPTR << std::endl;
	std::cout << "Ref adress: " << &stringREF << std::endl;
	std::cout << "////Values////" << std::endl;
	std::cout << "Str value: " << str << std::endl;
	std::cout << "Ptr value: " << stringPTR << std::endl;
	std::cout << "Ref value: " << stringREF << std::endl;
}
