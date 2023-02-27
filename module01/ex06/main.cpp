#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl Harl;
    if (argc > 2) {
        std::cerr << "Harl only accepts 1 argument!" << std::endl;
        return (EXIT_FAILURE);
    }
    Harl.complain(argv[1]);
}