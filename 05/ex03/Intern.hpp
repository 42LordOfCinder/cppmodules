#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class	Intern {
	public:
		Intern(void);
		Intern(Intern &it);
		Intern &operator=(Intern const &it);
		~Intern(void);
		AForm	*createSCF(std::string target);
		AForm	*createRRF(std::string target);
		AForm	*createPPF(std::string target);
		AForm	*makeForm(std::string form, std::string target);
};

#endif
