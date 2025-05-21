#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
	private:
		const std::string	name;
		bool				isSigned;
		int					signGradeReq;
		int					execGradeReq;
	public:
		AForm(void);
		AForm(std::string name, int signGradeReq, int execGradeReq);
		AForm(AForm &fr);
		AForm &operator=(AForm const &fr);
		virtual ~AForm(void);
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGradeReq() const;
		int					getExecGradeReq() const;
		void				beSigned(Bureaucrat bc);
		virtual void		execute(Bureaucrat const &executor) const = 0;
		class	GradeTooHighException : public std::exception {
			const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			const char	*what() const throw();
		};
};
std::ostream	&operator<<(std::ostream &out, AForm const &fr);

#endif
