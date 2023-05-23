#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iostream>

using std::cout;
using std::endl;


template <typename T>
class MutantStack: public std::stack<T> {

public:
	MutantStack() { cout << "MutantStack constructed\n"; };
	~MutantStack() { cout << "MutantStack destructed\n"; };

	MutantStack(MutantStack<T> &obj) {
		cout << "MutantStack Constructed by copy\n";
		this->c = obj.c;
	};

	MutantStack &operator=(MutantStack<T> &obj) {
		cout << "MutantStack operator=\n";
		this->c = obj.c;
		return *this;
	};

	typedef typename MutantStack<T>::container_type::iterator iterator;
	typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;



	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

template <typename T>
typename MutantStack<T>::iterator& operator++(typename MutantStack<T>::iterator& it) {
	cout << "test\n";
	++it;
	return it;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, MutantStack<T> &rhs) {
	for (typename MutantStack<T>::iterator it = rhs.begin(); it != rhs.end(); it++)
		os << *it << " ";
	return os;
}

#endif
