#include "Account.hpp"
#include <iostream>
#include <time.h>

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

// Constructor - Destructor
Account::Account(int initial_deposit) {
    static int creationIndex;

    this->_accountIndex = creationIndex;
    _displayTimestamp();
    std::cout << "index:"
              << this->_accountIndex << ";" << "amount:" << initial_deposit << ';'
              << "created" << std::endl;
    creationIndex++;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
}

Account::~Account() {
    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "closed" << std::endl;
}
// Display functions

void Account::_displayTimestamp() {
    time_t      rawTime;
    struct  tm  *timeInfo;
    char    buffer[80];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    //time format: Year / day / month || / Hour / Minutes / Seconds
    strftime(buffer, 80, "%Y%d%m_%H%M%S", timeInfo);
    std::cout << "[" << buffer << "]" << " ";
}


void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "p_amount:" << this->_amount << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << this->_amount + deposit << ";"
        << "nb_deposits:" << this->_nbDeposits + 1 << std::endl;
        this->_amount += deposit;
        _totalNbDeposits++;

}

bool Account::makeWithdrawal(int withdrawal) {
    bool approvedWithdrawal;

    if (withdrawal > this->_amount)
        approvedWithdrawal = true;
    else
        approvedWithdrawal = false;
    _displayTimestamp();
    std::cout
            << "index:" << this->_accountIndex << ";"
            << "p_amount:" << this->_amount << ";"
            << "withdrawal:";
    if (!approvedWithdrawal) {
        std::cout << "refused" << std::endl;
        return (approvedWithdrawal);
    } else {
        this->_nbDeposits++;
        _totalNbDeposits++;
        std::cout
            << withdrawal << ";"
            << "amount:" << this->_amount - withdrawal << ";"
            << "nb_withdrawals:" << this->_nbWithdrawals << ";"
            << std::endl;
    }

    return (approvedWithdrawal);
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout
        << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << std::endl;

}


void Account::displayStatus() const {
    _displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "amount: " << this->_amount << ";"
        << "deposits:" << this->_nbDeposits << ";"
        << "withdrawals:" << this->_nbWithdrawals
        << std::endl;
}
