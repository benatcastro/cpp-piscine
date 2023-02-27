#include "Harl.hpp"

complain::Levels getComplainLevel(const std::string &level) {
    if (level == "DEBUG") return (complain::DEBUG);
    if (level == "INFO") return (complain::INFO);
    if (level == "WARNING") return (complain::WARNING);
    if (level == "ERROR") return (complain::ERROR);
    return (complain::DEFAULT);

}

void Harl::complain(std::string level) {
    switch (getComplainLevel(level)) {
        case (complain::DEBUG):
            Harl::debug();
            break;
        case (complain::INFO):
            Harl::info();
            break;
        case (complain::WARNING):
            Harl::warning();
            break;
        case (complain::ERROR):
            Harl::error();
            break;
        default:
            return;
    }

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

