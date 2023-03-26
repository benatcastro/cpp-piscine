#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
system("leaks Polymorphism");
return 0;
}
