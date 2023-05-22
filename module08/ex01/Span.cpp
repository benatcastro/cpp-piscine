#include "Span.hpp"


Span::Span(): _maxElements(0), _currentElements(0), _array(new int[_maxElements]) {
	std::cout << "Span constructed with: " << _maxElements << " max elements\n";

}

Span::Span(unsigned  int N): _maxElements(N), _currentElements(0), _array(new int[_maxElements]) {
	std::cout << "Span constructed with: " << _maxElements << " max elements\n";

}

Span::Span(const Span &obj):	_maxElements(obj._maxElements),
								_currentElements(obj._currentElements),
								_array(new int[_maxElements])
{
	std::cout << "Span constructed by copy\n";
	for (unsigned int i = 0; i < this->_currentElements; i++)
		this->_array[i] = obj._array[i];
}

Span &Span::operator=(const Span &obj) {
	std::cout << "Span operator=\n";

	if (this->_array)
		delete [] this->_array;
	this->_array = new int[obj._maxElements];

	for (unsigned int i = 0; i < obj._maxElements; i++)
		this->_array[i] = obj._array[i];

	this->_currentElements = obj._currentElements;

	return *this;
}

Span::~Span() {
	delete [] this->_array;
	std::cout << "Span destructed\n";
}

unsigned int Span::size() { return this->_currentElements; }

void Span::addNumber(int x) {

	if (this->_currentElements + 1 > this->_maxElements)
		throw (std::out_of_range("Span is already full, can't add more elements"));
	else
		this->_array[_currentElements++] = x;
}

int &Span::operator[](unsigned int idx) {
	if (idx > this->_currentElements)
		throw (std::out_of_range("bad index"));
	else
		return this->_array[idx];
}

std::ostream &operator<<(std::ostream &os, Span &rhs) {

	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		os << rhs[i] << " ";
	}
	return (os);
}


int Span::shortestSpan() {
	return *(std::min_element(std::begin(this->_array), std::end(this->_array)));
}
