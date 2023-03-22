#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
std::cout << "=====================Wrong classes======================\n";
const WrongAnimal* meta0 = new WrongAnimal();
const WrongAnimal* k = new WrongCat();
std::cout << meta0->getType() << " " << std::endl;
std::cout << k->getType() << " " << std::endl;
std::cout << "Animal sound > "; meta0->makeSound();
std::cout << "Cat sound > "; k->makeSound();
delete meta0;
delete k;
std::cout << "=====================Working classes======================\n";
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << "Dog type:" << j->getType() << " " << std::endl;
std::cout << "Cat type:" << i->getType() << " " << std::endl;
std::cout << meta->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;
return 0;
}
