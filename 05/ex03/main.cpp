#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Intern		RandomIntern;
	AForm		*rrf;
	Bureaucrat	Francois("Francois", 1);

	rrf = RandomIntern.makeForm("robotomy request", "Bender");
	Francois.executeForm(*rrf);
	AForm	*test = RandomIntern.makeForm("test", "test");
	(void) test;
	AForm	*ppf = RandomIntern.makeForm("presidential pardon", "Gauthier");
	Francois.executeForm(*ppf);
	delete ppf;
	delete rrf;
	return 0;
}
