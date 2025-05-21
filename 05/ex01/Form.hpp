#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	private:
		const std::string	name;
		bool				isSigned;
		int					signGradeReq;
		int					execGradeReq;
	public:
		Form(void);
		Form(std::string name, int signGradeReq, int execGradeReq);
		Form(Form &fr);
		Form &operator=(Form const &fr);
		~Form(void);
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGradeReq() const;
		int					getExecGradeReq() const;
		void				beSigned(Bureaucrat bc);
		class	GradeTooHighException : public std::exception {
			const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			const char	*what() const throw();
		};
};
std::ostream	&operator<<(std::ostream &out, Form const &fr);

#endif
