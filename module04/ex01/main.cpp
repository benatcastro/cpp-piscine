#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
const Animal* j = new Dog();
const Animal* i = new Cat();

j->getIdeas();
std::cout <<std::endl;
i->getIdeas();

delete j;//should not create a leak
delete i;


std::cout << "============SCOPE TEST===================\n";
Dog basic;
{
    Dog tmp = basic;
}

system("leaks WorldOnFire");
return 0;
}
