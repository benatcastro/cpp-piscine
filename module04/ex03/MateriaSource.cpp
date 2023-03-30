#include "MateriaSource.hpp"
#include <iostream>
#include "Ice.hpp"

MateriaSource::MateriaSource() {
    std::cout << "Materia Source constructed\n";
    for (int i = 0; i < INVENTORY_SIZE; i++)
        _materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
    std::cout << "Materia source destructed\n";
//    for (int i = 0; i < INVENTORY_SIZE && _materias[i]; i++) {
//        std::cout << "Materia " << i << " " << _materias[i]->getType() << std::endl;
//    }
    for (int i = 0; i < INVENTORY_SIZE && _materias[i]; i++) {
        delete _materias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    std::cout << "Materia Source constructed by copy\n";
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        this->_materias[i] = obj._materias[i];
        delete obj._materias[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        this->_materias[i] = obj._materias[i];
        delete obj._materias[i];
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
    for (int i = 0; i < INVENTORY_SIZE; i++)
        if (!_materias[i]) {
            _materias[i] = materia;
            std::cout << BGREEN << "Learned materia: " << materia->getType() << " in slot: " << i << NC << std::endl;
            return;
        }
    std::cout << BGREEN << "Can't learn more materias\n" << NC;
    if (materia)
        delete materia;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < INVENTORY_SIZE && _materias[i]; i++) {
        if (this->_materias[i]->getType() == type) {
//            std::cout << "type: " << this->_materias[i]->getType() << " original: "<< type << "\n";
            std::cout << BGREEN << "Creating material: " << this->_materias[i]->getType() << " from slot: " << i << NC << std::endl;
            return (this->_materias[i]->clone());
        }
    }
    std::cout << BGREEN << "Cant't create materia " << type << NC << std::endl;
    return (0);
}
