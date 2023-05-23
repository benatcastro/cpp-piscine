#include "Span.hpp"
#include <limits>

Span::Span(): _maxElements(0) {
	std::cout << "Span constructed with: " << _maxElements << " max elements\n";

}

Span::Span(unsigned  int N): _maxElements(N) {
	std::cout << "Span constructed with: " << _maxElements << " max elements\n";

}

Span::Span(const Span &obj):	_maxElements(obj._maxElements), _vector(obj._vector) {
	std::cout << "Span constructed by copy\n";
}

Span &Span::operator=(const Span &obj) {
	this->_maxElements = obj._maxElements;
	this->_vector = obj._vector;

	return *this;
}

Span::~Span() {
	std::cout << "Span destructed\n";
}

unsigned int Span::size() { return this->_vector.size(); }

void Span::addNumber(int x) {

	if (this->_vector.size() + 1 > this->_maxElements)
		throw (std::out_of_range("Span is already full, can't add more elements"));
	else
		this->_vector.push_back(x);

}

int &Span::operator[](unsigned int idx) {
	if (idx > this->_vector.size() || (idx == 0 && this->_vector.size() == 0))
		throw (std::out_of_range("bad index"));
	else
		return this->_vector.at(idx);
}

std::ostream &operator<<(std::ostream &os, Span &rhs) {

	for (unsigned int i = 0; i < rhs.size(); i++)
		os << rhs[i] << " ";
	return (os);
}

int Span::shortestSpan() {

	if (this->_vector.size() < 2)
		throw (std::length_error("can't calculate shortest span with less than 2 elements on span"));

	std::vector<int> sorted_vector = this->_vector;

	std::sort(sorted_vector.begin(), sorted_vector.end());

	int res = std::numeric_limits<int>::max();

	for (std::vector<int>::iterator it = sorted_vector.begin() + 1; it < sorted_vector.end(); it++)
		*it - *(it - 1) < res ? res  = *it - *(it - 1) : res;
	return res;
}

int Span::longestSpan() {

	if (this->_vector.size() < 2)
		throw (std::length_error("can't calculate longest span with less than 2 elements on span"));

	std::vector<int> sorted_vector = this->_vector;

	int min = *std::min_element(sorted_vector.begin(), sorted_vector.end());
	int max = *std::max_element(sorted_vector.begin(), sorted_vector.end());

	return (max - min);
}

std::vector<int>::iterator Span::begin() { return this->_vector.begin(); }

std::vector<int>::iterator Span::end() { return this->_vector.end(); }

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

	srand(time(NULL));

	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		if (this->_vector.size() + 1 > this->_maxElements)
			throw (std::out_of_range("Span is already full, can't add more elements"));
		else
			this->_vector.push_back(rand());
	}


}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end, unsigned int max) {

	srand(time(NULL));

	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		if (this->_vector.size() + 1 > this->_maxElements)
			throw (std::out_of_range("Span is already full, can't add more elements"));
		else
			this->_vector.push_back(rand() % max);
	}

}
