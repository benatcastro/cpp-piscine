#include "SedIsForLosers.hpp"


/*
Replace every occurrence of s1 with s2 in the string s
*/
static void replaceString(std::string haystack, const std::string needle, const std::string replace) {

	std::size_t occurrenceIndex = 0;
	while (occurrenceIndex != haystack.npos)
	{
		occurrenceIndex = haystack.find(needle, occurrenceIndex);
		haystack.erase(occurrenceIndex, needle.length());
		haystack.insert(occurrenceIndex, replace);
		occurrenceIndex = haystack.find(needle, occurrenceIndex);
	}
}

int main(int argc, char **argv) {
	std::ifstream	inFile;

	// Init

	if (argc != MIN_ARGS)
	{
		std::cout << HELPER_MSG << std::endl;
		return 0;
	}
	inFile.open(argv[FILE_INDEX]);
	if (!inFile.is_open())
	{
		std::cerr << ERR_OPEN_MSG << argv[FILE_INDEX] << std::endl;
		return (0);
	}

	std::stringstream	inFileBuffer;

	const std::string	s1(argv[S1_INDEX]);
	const std::string	s2(argv[S2_INDEX]);
	inFileBuffer << inFile.rdbuf();
	inFile.close();

	// Replace logic
	replaceString(inFileBuffer.str(), s1, s2);


}
