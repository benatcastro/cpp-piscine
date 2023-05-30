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

	timeval init_vector_start, init_vector_end, sort_vector_start, sort_vector_end;
	timeval init_deque_start, init_deque_end, sort_deque_start, sort_deque_end;

	cout << "Before: ";
	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
		cout << *it << " ";
	cout << endl;



	// Vector start
	gettimeofday(&init_vector_start, NULL);
	std::vector<int> vector;
	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
		vector.push_back(*it);
	gettimeofday(&init_vector_end, NULL);

	// Vector sort
	gettimeofday(&sort_vector_start, NULL);
	Sorter(vector, vector.begin(), vector.end() - 1);
	gettimeofday(&sort_vector_start, NULL);


	//Deque
	gettimeofday(&init_deque_start, NULL);
	std::deque<int> deque;
	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
	deque.push_back(*it);
	gettimeofday(&init_deque_end, NULL);

	// Deque sort
	gettimeofday(&sort_deque_start, NULL);
	Sorter(deque, deque.begin(), deque.end() - 1);
	gettimeofday(&sort_deque_end, NULL);


	gettimeofday(&sort_vector_end, NULL);
	cout << "After Vector: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		cout << *it << " ";
	cout << endl;
	(isSorted(vector) == true ? cout << "Correctly sorted!\n" : cout << "Error sorting!\n");

	cout << "After Deque: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		cout << *it << " ";
	cout << endl;
	(isSorted(deque) == true ? cout << "Correctly sorted!\n" : cout << "Error sorting!\n");
	cout << endl;
	cout	<< "Time to initialize a range of "
			<< argc - 1
			<< " elements with std::vector: "
			<< init_vector_end.tv_usec - init_vector_start.tv_usec << "us\n"
			<< "Time to sort a range of "
			<< argc - 1
			<< " elements with std::vector: "
			<< sort_vector_end.tv_usec - sort_vector_start.tv_usec << "us\n"
			<< "Total time for std::vector: "
			<< sort_vector_end.tv_usec - init_vector_start.tv_usec << "us\n";


	cout	<< "Time to initialize a range of "
			<< argc - 1
			<< " elements with std::deque: "
			<< init_deque_end.tv_usec - init_deque_start.tv_usec << "us\n"
			<< "Time to sort a range of "
			<< argc - 1
			<< " elements with std::deque: "
			<< sort_deque_end.tv_usec - sort_deque_start.tv_usec << "us\n"
			<< "Total time for std::deque: "
			<< sort_deque_end.tv_usec - init_deque_start.tv_usec << "us\n";


}
