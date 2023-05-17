#include "Base.hpp"
#include <iostream>
#include <time.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base() { std::cout << "Base constructed\n"; }

Base::~Base() { std::cout << "Base destructed\n"; }


Base *Base::generate() {


	srand(time(NULL));

	int r = rand() % 3;
	switch (r) {
		case 0:
			return new A;
			break;
		case 1:
			return new B;
			break;
		case 2:
			return new C;
			break;
		default:
			std::cout << "Error kaboom\n";

	}

	return new Base;

}

