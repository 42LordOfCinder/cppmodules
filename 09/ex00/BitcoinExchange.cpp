#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &be) {(void) be;}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &be) {
	if (this != &be) {
		this->rates = be.rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string	BitcoinExchange::trim(std::string const &str) {
	size_t	start = 0;
	size_t	end = str.length() - 1;

	while (start <= end && std::isspace(str[start])) {
		++start;
	}
	while (end >= start && std::isspace(str[end])) {
		--end;
	}
	return str.substr(start, end - start + 1);
}

bool	BitcoinExchange::checkValue(std::string value, float *fValue) {
	size_t	start = 0;
	bool	dot = false;
	bool	nan = false;

	if (value[0] == '-')
		start = 1;
	for (size_t i = start; i < value.length(); i++) {
		if (!std::isdigit(value[i]) && value[i] != '.')
			nan = true;
		if (value[i] == '.') {
			if (dot == true || i == start || i == value.length() - 1)
				nan = true;
			dot = true;
		}
	}
	if (nan) {
		std::cout << "Error: not a number" << std::endl;
		return false;
	}
	std::stringstream	ss(value);
	ss >> *fValue;
	if (*fValue < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return false;
	}
	if (*fValue > 1000) {
		std::cout << "Error: value can not exceed 1000" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::validDate(int year, int month, int day) {
	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	static const int	daysInMonth[] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	int	days = daysInMonth[month];
	if (month == 2) {
		bool leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		if (leap)
			days = 29;
	}
	return day >= 1 && day <= days;
}

bool	BitcoinExchange::checkDate(std::string date) {
	std::string	year, month, day;
	int			iYear, iMonth, iDay;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++) {
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return false;
	}
	std::stringstream	ss(date);
	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day);
	std::stringstream	ss2(year), ss3(month), ss4(day);
	ss2 >> iYear, ss3 >> iMonth, ss4 >> iDay;
	return validDate(iYear, iMonth, iDay);
}

bool	BitcoinExchange::loadData() {
	std::ifstream	dataFile("data.csv");
	std::string		line, key, value;
	float			fValue;
	
	if (!dataFile.is_open()) {
		std::cerr << "Error: data file is missing" << std::endl;
		return false;
	}
	std::getline(dataFile, line);
	while (std::getline(dataFile, line)) {
		std::istringstream	ss(line);
		if (std::getline(ss, key, ',') && std::getline(ss, value)) {
			std::stringstream	ss2(value);
			ss2 >> fValue;
			this->rates[key] = fValue;
		}
	}
	dataFile.close();
	return true;
}

bool	BitcoinExchange::loadInput(char *file) {
	std::string	line;

	this->inputFile.open(file);
	if (!this->inputFile.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return false;
	}
	std::getline(this->inputFile, line);
	if (trim(line) != "date | value") {
		std::cerr << "Error: wrong file header" << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::process() {
	std::string	line, date, value;
	float		fValue;

	while (std::getline(this->inputFile, line)) {
		if (line != "") {
			std::istringstream	ss(line);
			if (std::getline(ss, date, '|') && std::getline(ss, value)) {
				date = trim(date), value = trim(value);
				if (checkValue(value, &fValue)) {
					if (checkDate(date)) {
						std::map<std::string, float>::iterator	it = this->rates.lower_bound(date);
						if (it->first != date && it != this->rates.begin())
							--it;
						std::cout << date << " => " << value << " = " << fValue * it->second << std::endl;
					}
					else
						std::cout << "Error: not a valid date" << std::endl;
				}
			}
			else
				std::cout << "Error: bad input => " << date << std::endl;
		}
	}
	this->inputFile.close();
}
