#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
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

	unsigned int				size(void);
	void						addNumber(int x);
	int 						shortestSpan(void);
	int 						longestSpan(void);
	void 						fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void 						fill(std::vector<int>::iterator begin, std::vector<int>::iterator end, unsigned int max);

	std::vector<int>::iterator	begin(void);
	std::vector<int>::iterator	end(void);


private:
	unsigned int		_maxElements;
	std::vector<int>	_vector;

};

std::ostream &operator<<(std::ostream &os, Span &rhs);

#endif
