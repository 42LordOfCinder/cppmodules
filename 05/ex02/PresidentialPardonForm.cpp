#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), target("t") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &ppf): AForm(ppf), target(ppf.target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf) {
	this->target = ppf.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getExecGradeReq())
		throw(GradeTooLowException());
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
