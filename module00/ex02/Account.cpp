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

// Display functions

void Account::_displayTimestamp() {
    //todo timestamp
    std::cout << "[" << std::time(nullptr) / 60 << "]"<< " ";

}

Account::Account(int initial_deposit) {

    _displayTimestamp();
    std::cout << " " << "index:"
        << getNbAccounts() << ";" << "amount:" << initial_deposit << ';'
        << "created" << std::endl;
    _totalAmount += initial_deposit;
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
    _displayTimestamp();
    std::cout
        << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << std::endl;

}

Account::~Account() {
    std::cout << "Destructor called" << std::endl;
}

void Account::displayStatus() const {
    static int index;

    get
}
