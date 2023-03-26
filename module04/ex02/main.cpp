#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {

//    const Animal test;
    const Dog* j = new Dog();
    const Cat* i = new Cat();

    i->getType();
    j->getType();

    i->makeSound();
    j->makeSound();

    i->getIdeas();
    j->getIdeas();
    delete j;//should not create a leak
    delete i;
system("leaks Abstract");
return 0;
}
