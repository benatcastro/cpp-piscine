#include <iostream>
#include <string>

void upperPrint(const char *argv) {
	std::string str(argv);
	std::string::iterator it;

	for (std::string::iterator it = str.begin(); it != str.end(); it++) *it = toupper(*it);
	std::cout << str << std::endl;
}

int main (int argc, char *argv[]) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	for(int i = 1; i < argc; i++)
		upperPrint(argv[i]);
}
