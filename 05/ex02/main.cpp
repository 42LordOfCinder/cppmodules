#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	Bureaucrat	Francois("Francois", 130);
	ShrubberyCreationForm	SCF("cible");
	Francois.executeForm(SCF);
	RobotomyRequestForm	RRF("cible");
	Francois.executeForm(RRF);
	Bureaucrat	Mateo("Mateo", 6);
	Mateo.executeForm(RRF);
	PresidentialPardonForm	PPF("cible");
	Mateo.executeForm(PPF);
	Mateo.incr();
	Mateo.executeForm(RRF);
	Mateo.executeForm(PPF);
	return 0;
}
