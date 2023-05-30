#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include "string"
# include "vector"
# include "list"
# include <deque>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

void parseInput(std::list<int> &input_list, int argc, char **argv);
bool isValidInteger(string str);

template <class Container>
void InsertSort(Container &container)
{
	for (typename Container::iterator it = container.begin() + 1; it != container.end(); it++)
	{
		typename Container::iterator j = it;
		while (j != container.begin() && *j < *(j - 1) )
		{
			std::iter_swap(j, j - 1);
			j--;
		}
	}
}

template <typename Container, typename Iter>
void Sorter(Container &numbers, Iter begin, Iter end)
{
	if (end - begin <= 1)
	{
		if (*begin > *end)
			std::iter_swap(end, begin);
	}
	if (numbers.size() < 32)
	{
		InsertSort(numbers);
		return;
	}
	else
	{
		Iter half = begin + ((end - begin) / 2);
		Sorter(numbers, half + 1, end);
		Sorter(numbers, begin, half);
		std::inplace_merge(begin, half + 1, end + 1);
	}
}

# endif
