#include "sys/time.h"
#include "PmergeMe.hpp"

int main(int argc, char __unused **argv)
{
	if (argc < 2)
		return (cerr << "You must enter some values!\n", 1);

	std::list<int>input;
	try
	{
		parseInput(input, argc, argv);
	}
	catch (std::exception &e)
	{
		cerr << "Error: "  << e.what() << endl;
		return (EXIT_FAILURE);
	}

	timeval start_time;
	timeval end_time;



// Vector start
	gettimeofday(&start_time, NULL);
	std::vector<int> vector;
	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
		vector.push_back(*it);
	gettimeofday(&end_time, NULL);
	cout	<< "Time to initialize a range of "
			<< argc - 1
			<< " elements with std::vector: "
			<< end_time.tv_usec - start_time.tv_usec << "us\n";

	gettimeofday(&start_time, NULL);
	Sorter(vector, vector.begin(), vector.end() - 1);
	gettimeofday(&end_time, NULL);
	cout	<< "Time to sort a range of "
			<< argc - 1
			<< " elements with std::vector: "
			<< end_time.tv_usec - start_time.tv_usec << "us\n";


	// Deque start
	gettimeofday(&start_time, NULL);
	std::deque<int> deque;
	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
		deque.push_back(*it);
	gettimeofday(&end_time, NULL);
	cout	<< "Time to initialize a range of "
		<< argc - 1
		<< " elements with std::deque: "
		<< end_time.tv_usec - start_time.tv_usec << "us\n";

	gettimeofday(&start_time, NULL);
	Sorter(deque, deque.begin(), deque.end());
	gettimeofday(&end_time, NULL);
	cout	<< "Time to sort a range of "
			<< argc - 1
			<< " elements with std::deque: "
			<< end_time.tv_usec - start_time.tv_usec << "us\n";

}
