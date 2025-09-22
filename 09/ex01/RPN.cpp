#include <iostream>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN &rpn) {(void) rpn;}

RPN	&RPN::operator=(RPN const &rpn) {
	if (this != &rpn) {
		this->op = rpn.op;
	}
	return *this;
}

RPN::~RPN() {}

bool	RPN::solve(char *arg) {
	int		o1, o2, j = 0, res;
	char	ops[4] = {'+', '-', '*', '/'};

	for (size_t i = 0; arg[i]; i++) {
		if (!std::isspace(arg[i])) {
			if (std::isdigit(arg[i])) {
				this->op.push(arg[i] - 48);
			} else {
				if (this->op.size() < 2)
					return false;
				o2 = this->op.top();
				this->op.pop();
				o1 = this->op.top();
				this->op.pop();
				for (j = 0; j < 4; j++)
					if (ops[j] == arg[i])
						break ;
				switch (j) {
					case 0:
						res = o1 + o2;
						break ;
					case 1:
						res = o1 - o2;
						break ;
					case 2:
						res = o1 * o2;
						break ;
					case 3:
						if (o2 == 0)
							return false;
						res = o1 / o2;
						break ;
				}
				this->op.push(res);
			}
		}
	}
	if (this->op.size() != 1)
		return false;
	std::cout << this->op.top() << std::endl;
	return true;
}
