#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
    return (_nbAccounts);
}

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit) {

    //todo timestamp
    std::time_t result = std::time(nullptr);
    std::cout << "[" << result << "]" << " " << "index:"
        << getNbAccounts() << ";" << "amount:" << initial_deposit << ';'
        << "created" << std::endl;
    _nbAccounts++;
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
