#include "Span.hpp"



int main(void)
{

	std::cout << "\n\n****Copy constructor****\n\n";

	try {
		Span sp_one(5);

		sp_one.fill(sp_one.begin(), sp_one.begin() + 5, 10);
		std::cout << "Sp one-> " << sp_one << std::endl;
		{
			Span sp_two(sp_one);
			std::cout << "Sp copy-> " << sp_two << std::endl;

		}
		std::cout << "Sp one-> " << sp_one << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n****Assignment operator****\n\n";

	try {
		Span sp_one(5);

		sp_one.fill(sp_one.begin(), sp_one.begin() + 5, 10);
		std::cout << "Sp one-> " << sp_one << std::endl;
		{
			Span sp_two;
			sp_two = sp_one;
			std::cout << "Sp copy-> " << sp_two << std::endl;
		}
		std::cout << "Sp one-> " << sp_one << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n****Adding numbers tests****\n\n";

	try {
		Span sp(0);

		sp.addNumber(1);
	}
	catch (std::exception &e) {
		std::cout << "O size exception-> "<< e.what() << std::endl;
	}

	try {
		Span sp(-1);

		sp.addNumber(1);
		std::cout << "Max unsigned int sp-> " << sp << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "O size exception-> "<< e.what() << std::endl;
	}
	try {
		Span sp(3);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		std::cout << "Sp-> " << sp << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Too many adds: "<< e.what() << std::endl;
	}

	std::cout << "\n\n****Shortest/Longest spans with less than two elems****\n\n";

	try {
		Span sp = Span(1);

		sp.addNumber(10);

		std::cout << "Span-> " << sp << std::endl;
		std::cout << "Shortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n****Shortest/Longest 10 elems spans****\n\n";

	try {
		Span sp = Span(10);

		sp.fill(sp.begin(), sp.end() + 10, 20);
		std::cout << "Span-> " << sp << std::endl;
		std::cout << "Shortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n****Shortest/Longest spans subject****\n\n";

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Span-> " << sp << std::endl;

		std::cout << "Shortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n****Shortest/Longest spans 10k elems****\n\n";

	try {
		Span sp = Span(15000);
		sp.fill(sp.begin(), sp.begin() + 15000);
//		std::cout << "Span-> " << sp << std::endl;

		std::cout << "Shortest span: "<< sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}
