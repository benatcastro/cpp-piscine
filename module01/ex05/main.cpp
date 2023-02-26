#include "Harl.hpp"

int main(void)
{
    Harl Harl;

    std::cout << "complain level: debug" <<std::endl;
    Harl.complain("debug");
    std::cout << "complain level: info" <<std::endl;
    Harl.complain("info");
    std::cout << "complain level: warning" <<std::endl;
    Harl.complain("warning");
    std::cout << "complain level: error" <<std::endl;
    Harl.complain("error");
}