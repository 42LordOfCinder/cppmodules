#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class	RPN {
	private:
		std::stack<int>	op;

	public:
		RPN();
		RPN(RPN &rpn);
		RPN	&operator=(RPN const &rpn);
		~RPN();
		bool	solve(char *arg);
};

#endif
