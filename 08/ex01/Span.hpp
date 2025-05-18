#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class	Span {
	private:
		std::vector<int>	v;
		unsigned int		N;
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const &sp);
		~Span(void);
		Span	&operator=(Span const &sp);
		void			addNumber(int n);
		void			addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int	getN(void) const;
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		class	NoSpaceException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		class	NoSpanException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif
