#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
    Brain(); // Default constructor ideas = NULL;
//    BrainInit(); // Initializes ideas to random texts;
    Brain(Brain const &obj); // Copy constructor
    ~Brain(); // Default destructor
    Brain const &operator=(Brain const &obj); // Assignment operator
    void    getIdeas(void);

private:
    std::string _ideas[100];
};

#endif
