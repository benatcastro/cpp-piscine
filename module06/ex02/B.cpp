#include "B.hpp"
#include "iostream"


B::B() { std::cout << "B constructed\n"; }

B::~B() { std::cout << "B destructed\n"; }

void B::dummy() {}
