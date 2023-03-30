#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Node.hpp"

int main(void) {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    (void)me;
    (void)src;
//    (void)tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);

    src->learnMateria(new Ice());
    me->unequip(0);
    me->unequip(1);
//    me->unequip(2);
//    me->unequip(3);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(2, *bob);
    delete bob;
    delete me;
    delete src;
    //system("leaks AlLeVoYyYyyYY");
    return 0;
}
