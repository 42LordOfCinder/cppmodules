#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	public:
		std::string	target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &rrf);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rrf);
		~RobotomyRequestForm(void);
		void	execute(Bureaucrat const &executor) const;
};

#endif
