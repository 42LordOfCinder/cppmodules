#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	public:
		std::string	target;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &scf);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &scf);
		~ShrubberyCreationForm(void);
		void	execute(Bureaucrat const &executor) const;
};

#endif
