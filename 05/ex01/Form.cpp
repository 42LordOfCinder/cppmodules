#include "Form.hpp"

Form::Form(void): name("F"), isSigned(false), signGradeReq(1), execGradeReq(1) {}

Form::Form(std::string name, int signGradeReq, int execGradeReq): name(name), isSigned(false) {
	if (signGradeReq < 1 || execGradeReq < 1)
		throw(GradeTooHighException());
	if (signGradeReq > 150 || execGradeReq > 150)
		throw(GradeTooLowException());
	this->signGradeReq = signGradeReq;
	this->execGradeReq = execGradeReq;
}

Form::Form(Form &fr): name(fr.getName()), isSigned(fr.getIsSigned()), signGradeReq(fr.getSignGradeReq()), execGradeReq(fr.getExecGradeReq()) {}

Form &Form::operator=(Form const &fr) {
	this->isSigned = fr.getIsSigned();
	this->signGradeReq = fr.getSignGradeReq();
	this->execGradeReq = fr.getExecGradeReq();
	return *this;
}

Form::~Form(void) {}

const std::string	Form::getName(void) const {
	return this->name;
}

bool	Form::getIsSigned(void) const {
	return this->isSigned;
}

int	Form::getSignGradeReq(void) const {
	return this->signGradeReq;
}

int	Form::getExecGradeReq(void) const {
	return this->execGradeReq;
}

void	Form::beSigned(Bureaucrat br) {
	if (br.getGrade() > this->signGradeReq)
		throw(GradeTooLowException());
	this->isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

std::ostream	&operator<<(std::ostream &out, Form const &fr) {
	out << "Form " << fr.getName() << ", signed? " << fr.getIsSigned() << ", sign grade requirement " << fr.getSignGradeReq() << ", exec grade requirement " << fr.getExecGradeReq() << std::endl;
	return out;
}
