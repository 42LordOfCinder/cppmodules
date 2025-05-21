#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("B"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name,int grade): name(name) {
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &bc): name(bc.getName()) {
	this->grade = bc.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bc){
	this->grade = bc.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const std::string	Bureaucrat::getName(void) const {
	return this->name;
}

int	Bureaucrat::getGrade(void) const {
	return this->grade;
}

void	Bureaucrat::incr(void) {
	if (this->grade == 1)
		throw(GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decr(void) {
	if (this->grade == 150)
		throw(GradeTooLowException());
	this->grade++;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bc) {
	out << bc.getName() << ", bureaucrat grade " << bc.getGrade() << std::endl;
	return out;
}
