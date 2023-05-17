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
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			std::cout << "Error kaboom\n";

	}

	return new A;
}

void Base::identify(Base *p) {

	if (A *a = dynamic_cast<A *>(p)) {
		std::cout << "It's A!\n";
		delete p;
	}
	else if (B *b = dynamic_cast<B *>(p)) {
		std::cout << "It's B!\n";
		delete p;
	}
	else if (C *c = dynamic_cast<C *>(p)) {
		std::cout << "It's C!\n";
		delete p;
	}
	else
		std::cout << "Double kaboom!\n";
	return;

}

void Base::identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "It's A!\n";
		return;
	}
	catch (std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "It's B!\n";
		return;
	}
	catch (std::exception &e) {
	}
	try {
		C &b = dynamic_cast<C &>(p);
		(void)b;
		std::cout << "It's C!\n";
		return;
	}
	catch (std::exception &e) {
	}
}
