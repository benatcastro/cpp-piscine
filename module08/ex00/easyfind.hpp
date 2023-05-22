#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename Container>
typename Container::iterator easyfind(Container &container, int needle)
{
	typename Container::iterator res = std::find(container.begin(), container.end(), needle);
	if (res == container.end())
		throw (std::out_of_range("Couldn't find needle :("));
	return res;
}

#endif
