#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &bc);
		Bureaucrat &operator=(Bureaucrat const &bc);
		~Bureaucrat(void);
		const std::string	getName() const;
		int					getGrade() const;
		void	incr();
		void	decr();
		void	signForm(Form &fr);
		class	GradeTooHighException : public std::exception {
			const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			const char	*what() const throw();
		};
};
std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bc);

#endif
