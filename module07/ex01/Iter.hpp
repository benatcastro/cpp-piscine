#ifndef ITER_HPP
# define ITER_HPP


template <typename T>
void	iter(T *array, T len, T f(T))
{
	for (T i; i < len; i++)
	{
		(f)array[i];
	}
}

#endif
