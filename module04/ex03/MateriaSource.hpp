#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Defines.hpp"

class MateriaSource: public IMateriaSource {
private:
    AMateria    *_materias[INVENTORY_SIZE];
public:
    MateriaSource(); // Def
    MateriaSource(MateriaSource const &obj); // Copy
    MateriaSource &operator=(MateriaSource const &obj); // Assignment overlaod
    ~MateriaSource(); // Destr
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
