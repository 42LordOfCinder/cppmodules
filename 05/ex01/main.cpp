#include "Form.hpp"

int	main(void) {
	Form	contrat("Contrat", 76, 86);
	Bureaucrat	Francoislebureaucrate("Francois", 75);
	Francoislebureaucrate.signForm(contrat);
	Form	grosContrat("Gros Contrat", 2, 2);
	Francoislebureaucrate.signForm(grosContrat);
}
