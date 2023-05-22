#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>

class Span {

public:
	Span();
	Span(unsigned int N);
	Span(const Span &obj);
	~Span();

	Span &operator=(const Span &obj);
	int &operator[](unsigned int idx);

	unsigned int	size(void);
	void			addNumber(int x);
	int 			shortestSpan();
	int 			longestSpan();


private:
	unsigned int	_maxElements;
	unsigned int	_currentElements;
	int				*_array;


};

std::ostream &operator<<(std::ostream &os, Span &rhs);

#endif
