#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), target("t") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rrf): AForm(rrf), target(rrf.target) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rrf) {
	this->target = rrf.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getExecGradeReq())
		throw(GradeTooLowException());
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cerr << "the robotomy has failed" << std::endl;
}
