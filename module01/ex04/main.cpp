#include "SedIsForLosers.hpp"

// static std::string *findOcurrences(const std::string s1, const std::string s2) {
// 	return (NULL);
// }

// static std::string replaceString(const std::string s1, const std::string s2) {
// 	std::string	outStr;

// 	return (outStr);
// }

int main(int argc, char **argv) {
	std::ifstream	inFile;

	if (argc != MIN_ARGS) {
		std::cout << HELPER_MSG << std::endl;
		return 0;
	}
	inFile.open(argv[FILE_INDEX]);
	if (!inFile.is_open()) {
		std::cerr << ERR_OPEN_MSG << argv[FILE_INDEX] << std::endl;
		return (0);
	}

	std::stringstream	inFileBuffer;
	const std::string	s1(argv[S1_INDEX]);
	const std::string	s2(argv[S2_INDEX]);

	inFileBuffer << inFile.rdbuf();
	std::cout << inFileBuffer.str();
	inFile.close();
}
