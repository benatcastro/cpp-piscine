#include <iostream>
#include <string>
#include <map>
#include "phonebook.h"


static void promptHandler (std::string cmd) {
	if (cmd == "ADD")
		std::cout << "ADD CMD" << std::endl;
	else if (cmd == "SEARCH")
		std::cout << "SEARCH CMD" << std::endl;
	else if (cmd == "EXIT")
		exit(EXIT_SUCCESS);
	else
		std::cout << "cmd not found try again with: <ADD> <SEARCH> <EXIT>" << std::endl;
}

int main (void) {
	std::string promptCmd;

	while (true) {
		std::cout << PROMPT;
		std::cin >> promptCmd;
		promptHandler(promptCmd);
	}
}
