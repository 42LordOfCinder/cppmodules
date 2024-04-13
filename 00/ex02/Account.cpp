#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

int	Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp(void) {
	time_t	currentTime = time(NULL);
	tm		*localTime = localtime(&currentTime);
	char	formattedTime[20];

	strftime(formattedTime, sizeof(formattedTime), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << formattedTime << "] ";
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:";
	std::cout << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "refused" << std::endl;
	return false;
}

int	Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";closed" << std::endl;
	this->_nbAccounts--;
}
