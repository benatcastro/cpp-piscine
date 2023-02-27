#include "SedIsForLosers.hpp"

/*
Replace every occurrence of s1 with s2 in the string s
*/
static std::string replaceString(std::string haystack, const std::string needle, const std::string replace) {
    std::size_t occurrenceIndex = 0;
    while (haystack.find(needle, occurrenceIndex) != std::string::npos)
    {
        occurrenceIndex = haystack.find(needle, occurrenceIndex);
        haystack.erase(occurrenceIndex, needle.length());
        haystack.insert(occurrenceIndex, replace);
        occurrenceIndex += replace.length();
    }
    return (haystack);
}

int main(int argc, char **argv) {
	std::ifstream	inFile;

	if (argc != MIN_ARGS) {
		std::cout << HELPER_MSG << std::endl;
		return (EXIT_FAILURE);
	}
	inFile.open(argv[FILE_INDEX]);
	if (!inFile.is_open()) {
		std::cerr << ERR_OPEN_MSG << argv[FILE_INDEX] << std::endl;
		return (EXIT_FAILURE);
	}
    if (!argv[S1_INDEX] || !argv[S2_INDEX]) {
        std::cerr << ERR_NO_INPUT << std::endl;
        return (EXIT_FAILURE);
    }
	std::stringstream	inFileBuffer;

	const std::string	s1(argv[S1_INDEX]);
	const std::string	s2(argv[S2_INDEX]);
	inFileBuffer << inFile.rdbuf();
    if (!inFileBuffer) {
        std::cout << argv[FILE_INDEX] << " " << "is empty" << std::endl;
        return  (EXIT_FAILURE);
    }
	inFile.close();
    std::ofstream outFile(strcat(argv[FILE_INDEX],".replace"));
    outFile << replaceString(inFileBuffer.str(), s1, s2);
}
