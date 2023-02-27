#include "Harl.hpp"

int main(void)
{
    Harl Harl;

    std::cout << "complain level: debug" <<std::endl;
    Harl.complain("DEBUG");
    std::cout << "complain level: info" <<std::endl;
    Harl.complain("INFO");
    std::cout << "complain level: warning" <<std::endl;
    Harl.complain("WARNING");
    std::cout << "complain level: error" <<std::endl;
    Harl.complain("ERROR");
}