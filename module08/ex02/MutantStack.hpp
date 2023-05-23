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

	typedef typename MutantStack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }

	iterator end() { return this->c.end(); }



};

#endif
