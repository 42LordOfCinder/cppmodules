#include "PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <cmath>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe &pmm) {(void) pmm;}

PmergeMe	&PmergeMe::operator=(PmergeMe const &pmm) {(void) pmm; return *this;}

PmergeMe::~PmergeMe() {}

size_t	PmergeMe::getSize() {
	return this->tmp.size();
}

bool	PmergeMe::parse(char **argv) {
	for (char **p = argv; *p != NULL; p++) {
		char	*s = *p;
		if (*s == 0)
			return false;
		int	result = 0;
		while (*s) {
			if (*s < '0' || *s > '9')
				return false;
			int	digit = *s - '0';
			if (result > (INT_MAX - digit) / 10)
				return false;
			result = result * 10 + digit;
			++s;
		}
		this->tmp.push_back(result);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < this->tmp.size(); i++)
		std::cout << " " << tmp[i];
	std::cout << std::endl;
	return true;
}

void	PmergeMe::getVec() {
	for (size_t i = 0; i < this->tmp.size(); i++)
		this->vec.push_back(this->tmp[i]);
}

void	PmergeMe::getDeq() {
	for (size_t i = 0; i < this->tmp.size(); i++)
		this->deq.push_back(this->tmp[i]);
}

int	PmergeMe::jacob(int n) {
	return static_cast<int>(round((pow(2, n) - pow(-1, n)) / 3));
}

void	PmergeMe::print() {
	std::cout << "After: ";
	for (std::deque<int>::iterator it = this->deq.begin(); it != this->deq.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

bool	compVec(std::vector<int>::iterator a, std::vector<int>::iterator b) {
	return *a < *b;
}

bool	compDeq(std::deque<int>::iterator a, std::deque<int>::iterator b) {
	return *a < *b;
}

void	PmergeMe::swapPairsVec(int pair1, int pair2, size_t pairSize) {
	for (size_t i = 0; i < pairSize; i++) {
		int	tmp = this->vec[pair2 - i];
		this->vec[pair2 - i] = this->vec[pair1 - i];
		this->vec[pair1 - i] = tmp;
	}
}

void	PmergeMe::swapPairsDeq(int pair1, int pair2, size_t pairSize) {
	for (size_t i = 0; i < pairSize; i++)
		std::swap(this->deq[pair2 - i], this->deq[pair1 - i]);
}

void	PmergeMe::sortVec(int level) {
	size_t	eltNb = this->vec.size() / level;
	size_t	pairSize = level * 2;
	bool	odd = eltNb % 2 == 1;
	std::vector<int>									whole;
	std::vector<std::vector<int>::iterator>				pend, main;
	std::vector<std::vector<int>::iterator>::iterator	it, bound, upper;

	if (eltNb < 2)
		return ;
	for (size_t i = 1; i <= eltNb / 2; i++)
		if (this->vec[i * pairSize - 1] < this->vec[i * pairSize - level - 1])
			swapPairsVec(i * pairSize - 1, i * pairSize - level - 1, level);
	sortVec(level * 2);
	main.push_back(this->vec.begin() + level - 1);
	for (size_t i = 2; i <= eltNb; i++) {
		if (i % 2)
			pend.push_back(this->vec.begin() + (i * level) - 1);
		else
			main.push_back(this->vec.begin() + (i * level) - 1);
	}
	int	prevJac = 1;
	int	inserted = 0;
	for (int j = 3;; j++) {
		int	currJac = jacob(j);
		int	diff = currJac - prevJac;
		if (diff > static_cast<int>(pend.size()))
			break ;
		for (int toInsert = diff; toInsert > 0; toInsert--) {
			it = pend.begin() + toInsert - 1;
			bound = main.begin() + currJac + inserted;
			upper = std::upper_bound(main.begin(), bound, *it, compVec);
			main.insert(upper, *it);
			pend.erase(it);
		}
		inserted += diff;
		prevJac = currJac;
	}
	for (ssize_t i = pend.size() - 1; i >= 0; i--) {
		it = pend.begin() + i;
		bound = main.begin() + main.size() - pend.size() + i + odd;
		upper = std::upper_bound(main.begin(), bound, *it, compVec);
		main.insert(upper, *it);
	}
	for (it = main.begin(); it != main.end(); it++)
		for (int i = level - 1; i >= 0; i--)
			whole.push_back(*(*it - i));
	std::vector<int>::iterator	wholeIt = whole.begin();
	std::vector<int>::iterator	vecIt = this->vec.begin();
	while (wholeIt != whole.end()) {
		*vecIt = *wholeIt;
		vecIt++, wholeIt++;
	}
}

void	PmergeMe::sortDeq(int level) {
	size_t	eltNb = this->deq.size() / level;
	size_t	pairSize = level * 2;
	bool	odd = eltNb % 2 == 1;
	std::deque<int>										whole;
	std::deque<std::deque<int>::iterator>				pend, main;
	std::deque<std::deque<int>::iterator>::iterator	it, bound, upper;

	if (eltNb < 2)
		return ;
	for (size_t i = 1; i <= eltNb / 2; i++) {
		std::deque<int>::iterator	a = this->deq.begin();
		std::deque<int>::iterator	b = this->deq.begin();
		std::advance(a, i * pairSize - 1);
		std::advance(b, i * pairSize - level - 1);
		if (*a < *b)
			swapPairsDeq(i * pairSize - 1, i * pairSize - level - 1, level);
	}
	sortDeq(level * 2);
	main.push_back(this->deq.begin() + level - 1);
	for (size_t i = 2; i <= eltNb; i++) {
		if (i % 2)
			pend.push_back(this->deq.begin() + (i * level) - 1);
		else
			main.push_back(this->deq.begin() + (i * level) - 1);
	}
	int	prevJac = 1;
	int	inserted = 0;
	for (int j = 3;; j++) {
		int	currJac = jacob(j);
		int	diff = currJac - prevJac;
		if (diff > static_cast<int>(pend.size()))
			break ;
		for (int toInsert = diff; toInsert > 0; toInsert--) {
			it = pend.begin() + toInsert - 1;
			bound = main.begin() + currJac + inserted;
			upper = std::upper_bound(main.begin(), bound, *it, compDeq);
			main.insert(upper, *it);
			pend.erase(it);
		}
		inserted += diff;
		prevJac = currJac;
	}
	for (ssize_t i = pend.size() - 1; i >= 0; i--) {
		it = pend.begin() + i;
		bound = main.begin() + main.size() - pend.size() + i + odd;
		upper = std::upper_bound(main.begin(), bound, *it, compDeq);
		main.insert(upper, *it);
	}
	for (it = main.begin(); it != main.end(); it++)
		for (int i = level - 1; i >= 0; i--)
			whole.push_back(*(*it - i));
	std::deque<int>::iterator	wholeIt = whole.begin();
	std::deque<int>::iterator	deqIt = this->deq.begin();
	while (wholeIt != whole.end()) {
		*deqIt = *wholeIt;
		deqIt++, wholeIt++;
	}
}
