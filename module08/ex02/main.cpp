#include "MutantStack.hpp"
#include <vector>
#include "list"

int main(void)
{
	cout << "\n\n****Mutant Stack basic functions****\n\n";
	try {
		std::stack<int> stack;
		MutantStack<int> mstack;
		mstack.push(5);
		stack.push(5);
		mstack.push(17);
		stack.push(17);
		mstack.push(3);
		stack.push(3);
		mstack.push(5);
		stack.push(5);
		mstack.push(737);
		stack.push(737);
		cout << "Ms-> " << mstack << endl;
		mstack.pop();
		stack.pop();
		cout << "Ms after pop-> " << mstack << endl;
		cout << "Ms top-> " << mstack.top() << " | stack top->" << stack.top() << endl;
		cout << "Ms size-> " << mstack.size() << " | stack size->" << stack.size() << endl;
	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}

	MutantStack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);
	cout << "Original: " << original << endl;
	{
		MutantStack<int> copy(original);
		cout << "Copy: " << copy << endl;
	}
	cout << "Original after cons copy: " << original << endl;

	cout << "Original: " << original << endl;
	{
		MutantStack<int> assignment;
		assignment = original;
		cout << "Copy: " << assignment << endl;
	}
	cout << "Original after cons copy: " << original << endl;

	cout << "\n\n****Mutant Stack iterators functions****\n\n";
	try {
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
			cout << *it << " ";
		cout << endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
			cout << *it << " ";
		cout << endl;

	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}


	cout << "\n\n****List comparation****\n\n";

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	try {
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			cout << *it << " ";
		cout << endl;
		for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); it++)
			cout << *it << " ";
		cout << endl;

	}
	catch (std::exception &e) {
		cout << e.what() << endl;
	}

	cout << "\n\n****Construction****\n\n";

	cout << "Original: " << original << endl;
	{
		MutantStack<int> copy(original);
		cout << "Copy: " << copy << endl;
	}
	cout << "Original after cons copy: " << original << endl;
	{
		MutantStack<int> assignment;
		assignment = original;
		cout << "Assignment: " << assignment << endl;
	}
	cout << "Original assignment: " << original << endl;


	cout << "\n\n****Leaks****\n\n";
	system("leaks --quiet MutantStack");

	return 0;
}
