#include "Span.hpp"



int main(void)
{
	Span makelele(10);

	makelele.addNumber(1);
	makelele.addNumber(5);
	makelele.addNumber(2);
	makelele.addNumber(9);
	makelele.addNumber(6);

	std::cout << makelele << std::endl;
}
