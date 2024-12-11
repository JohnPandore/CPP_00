/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joncurci <joncurci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:25 by joncurci          #+#    #+#             */
/*   Updated: 2024/12/03 14:43:46 by joncurci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>



const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";



// Initialisation des membres statiques
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Méthodes privées

void Account::_displayTimestamp()
{
    // Récupérer l'heure actuelle
    std::time_t now = std::time(0);
    std::tm* local_time = std::localtime(&now);

    // Afficher l'horodatage au format [YYYYMMDD_HHMMSS]
    std::cout << "[" << (local_time->tm_year + 1900)
            << std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1)
            << std::setw(2) << std::setfill('0') << local_time->tm_mday
            << "_"
            << std::setw(2) << std::setfill('0') << local_time->tm_hour
            << std::setw(2) << std::setfill('0') << local_time->tm_min
            << std::setw(2) << std::setfill('0') << local_time->tm_sec
            << "] ";
}

// Constructeur et destructeur

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit),
    _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
            << ";amount:" << BLUE << _amount << RESET
            << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
            << ";amount:" << BLUE << _amount << RESET
            << ";closed" << std::endl;
}

// Méthodes d'instance

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
            << ";p_amount:" << BLUE << _amount << RESET
            << ";deposit:" << BLUE << deposit << RESET;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << BLUE << _amount << RESET
            << ";nb_deposits:" << BLUE << _nbDeposits << RESET << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
            << ";p_amount:" << BLUE << _amount << RESET
            << ";withdrawal:";

    if (_amount < withdrawal)
	{
        std::cout << "refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal
            << ";amount:" << BLUE << _amount << RESET
            << ";nb_withdrawals:" << BLUE << _nbWithdrawals << RESET << std::endl;

    return (true);
}

int Account::checkAmount() const
{
    return (_amount);
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << BLUE << _accountIndex << RESET
            << ";amount:" << BLUE << _amount << RESET
            << ";deposits:" << BLUE << _nbDeposits << RESET
            << ";withdrawals:" << BLUE << _nbWithdrawals << RESET << std::endl;
}

// Méthodes statiques

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << BLUE << _nbAccounts << RESET
            << ";total:" << BLUE << _totalAmount << RESET
            << ";deposits:" << BLUE << _totalNbDeposits << RESET
            << ";withdrawals:" << BLUE << _totalNbWithdrawals << RESET << std::endl;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}