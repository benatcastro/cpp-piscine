#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	std::cout << "========With pointer========\n";
	Base::identify(Base::generate());

	std::cout << "========With reference=========\n";

	Base *r = Base::generate();

	Base::identify(*r);

	delete r;

	std::cout << "\n\n=================\n";
	system("leaks --quiet Types");
}

