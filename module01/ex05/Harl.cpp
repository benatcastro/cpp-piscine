#include "Harl.hpp"

int getComplainLevel(const std::string &level) {
    std::string complainLevels[]    = {"debug", "info", "warning", "error"};
    for (int i = 0; i < 4; i++)
        if ( level == complainLevels[i])
            return (i);
    return (-1);
}

void Harl::complain(std::string level) {

    void    (Harl::*complainFncs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int     complainIndex;

    complainIndex = getComplainLevel(level);
    if (complainIndex != -1)
        (this->*complainFncs[complainIndex])();
}

void Harl::debug() {
    std::cout << DEBUG_MSG << std::endl;
}

void Harl::info() {
    std::cout << INFO_MSG << std::endl;
}

void Harl::warning() {
    std::cout << WARNING_MSG << std::endl;
}

void Harl::error() {
    std::cout << ERROR_MSG << std::endl;
}

