#include <list>
#include <iostream>
#include "MutantStack.hpp"

int	main(void) {
	std::cout << "Mutant Stack: " << std::endl;
	MutantStack<int>	m;
	m.push(5);
	m.push(17);
	std::cout << m.top() << std::endl;
	m.pop();
	std::cout << m.size() << std::endl;
	m.push(3);
	m.push(5);
	m.push(737);
	m.push(69);
	m.push(0);
	MutantStack<int>::iterator	it = m.begin();
	MutantStack<int>::iterator	ite = m.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(m);
	std::cout << std::endl << "List: " << std::endl;
	std::list<int>	l;
	l.push_back(5);
	l.push_back(17);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(69);
	l.push_back(0);
	std::list<int>::iterator	lit = l.begin();
	std::list<int>::iterator	lite = l.end();
	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}
	return 0;
}
