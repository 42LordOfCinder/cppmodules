#include "Span.hpp"

Span::Span(void): N(0) {}

Span::Span(unsigned int N): N(N) {}

Span::Span(Span const &sp) {*this = sp;}

Span::~Span(void) {};

Span	&Span::operator=(Span const &sp) {
	this->N = sp.getN();
	return *this;
}

void	Span::addNumber(int n) {
	if (this->v.size() >= N)
		throw NoSpaceException();
	v.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (std::distance(start, end) + this->v.size() >= this->N)
		throw NoSpaceException();
	this->v.insert(v.end(), start, end);
}

unsigned int	Span::getN(void) const {
	return (this->N);
}

unsigned int	Span::shortestSpan(void) {
	if (this->v.size() <= 1)
		throw NoSpanException();
	std::sort(this->v.begin(), this->v.end());
	int	minSpan = this->v[1] - this->v[0];
	for (int i = 2; i < (int) v.size(); i++)
		if (this->v[i] - this->v[i - 1] < minSpan)
			minSpan = this->v[i] - this->v[i - 1];
	return minSpan;
}

unsigned int	Span::longestSpan(void) {
	if (this->v.size() <= 1)
		throw NoSpanException();
	std::sort(this->v.begin(), this->v.end());
	return this->v[v.size() - 1] - this->v[0];
}

const char	*Span::NoSpaceException::what() const throw() {
	return "no space dawg";
}

const char	*Span::NoSpanException::what() const throw() {
	return "too few elements";
}
