#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern &it) {
	(void) it;
}

Intern &Intern::operator=(Intern const &it) {
	(void) it;
	return *this;
}

Intern::~Intern(void) {}

AForm	*Intern::createSCF(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createRRF(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createPPF(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string form, std::string target) {
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*ptrs[3])(std::string target);
	ptrs[0] = &Intern::createSCF;
	ptrs[1] = &Intern::createRRF;
	ptrs[2] = &Intern::createPPF;
	for (int i = 0; i < 3; i++) {
		if (form == forms[i]) {
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (this->*ptrs[i])(target);
		}
	}
	std::cerr << "Provided form name does not exist" << std::endl;
	return NULL;
}
