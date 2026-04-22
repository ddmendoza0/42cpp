#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts       = 0;
int Account::_totalAmount      = 0;
int Account::_totalNbDeposits  = 0;
int Account::_totalNbWithdrawals = 0;

int Account::checkAmount( void ) const  { return _amount; }
int Account::getNbAccounts( void )      { return _nbAccounts; }
int Account::getTotalAmount( void )     { return _totalAmount; }
int Account::getNbDeposits( void )      { return _totalNbDeposits; }
int Account::getNbWithdrawals( void )   { return _totalNbWithdrawals; }

void    Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm*    t = std::localtime(&now);

    std::cout << '[';
    std::cout << std::setw(4) << std::setfill('0') <<t->tm_year+1900;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mon+1;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mday;
    std::cout << '_';
    std::cout << std::setw(2) << std::setfill('0') <<t->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_sec;
    std::cout << ']' << ' ';
}

Account::Account(int initial_deposit) 
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << Account::checkAmount() << ';';
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "closed" << std::endl;
}

void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ';';
    std::cout << "total:" << getTotalAmount() << ';';
    std::cout << "deposits:" << getNbDeposits() << ';';
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << checkAmount() << ';';
    std::cout << "deposit:" << deposit << ';';
    _amount += deposit;
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ';';
        std::cout << "p_amount:" << checkAmount() << ';';
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << checkAmount() << ';';
    std::cout << "withdrawal:" << withdrawal << ';';
    _amount -= withdrawal;
    std::cout << "amount:" << checkAmount() << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}