#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>


template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
	return;
}

template <typename T>
void	iter(T *array, std::size_t len, void (*f)(T &))
{
	if (!f || !array)
		return;
	for (std::size_t i = 0; i < len; i++)
	{
		(f)(array[i]);
	}
}

#endif
