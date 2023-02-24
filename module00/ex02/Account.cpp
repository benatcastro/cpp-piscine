#include "Account.hpp"
#include <iostream>
#include <ctime>

//setters
int Account::getNbAccounts() {
    return (this->_nbAccounts);
}


Account::Account(int initial_deposit) {
    std::time_t result = std::time(nullptr);
    std::cout << "[" << result << "]" << " " << "index:"
        << getNbAccounts() << ";" << "amount:" << initial_deposit << ';'
        << "created" << std::endl;
}

void Account::makeDeposit(int deposit) {
    (void)deposit;
    std::cout << "makeDeposit\n";
}

bool Account::makeWithdrawal(int withdrawal) {
    (void)withdrawal;
    return (true);
}

void Account::displayAccountsInfos() {
    std::cout << "Display acc\n";
}

Account::~Account() {
    std::cout << "Destructor called" << std::endl;
}

void Account::displayStatus() const {
    std::cout << "Display status\n";
}
