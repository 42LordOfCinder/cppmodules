#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	public:
		std::string	target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &ppf);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &ppf);
		~PresidentialPardonForm(void);
		void	execute(Bureaucrat const &executor) const;
};

#endif
