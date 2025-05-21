#include "AForm.hpp"

AForm::AForm(void): name("F"), isSigned(false), signGradeReq(1), execGradeReq(1) {}

AForm::AForm(std::string name, int signGradeReq, int execGradeReq): name(name), isSigned(false) {
	if (signGradeReq < 1 || execGradeReq < 1)
		throw(GradeTooHighException());
	if (signGradeReq > 150 || execGradeReq > 150)
		throw(GradeTooLowException());
	this->signGradeReq = signGradeReq;
	this->execGradeReq = execGradeReq;
}

AForm::AForm(AForm &fr): name(fr.getName()), isSigned(fr.getIsSigned()), signGradeReq(fr.getSignGradeReq()), execGradeReq(fr.getExecGradeReq()) {}

AForm &AForm::operator=(AForm const &fr) {
	this->isSigned = fr.getIsSigned();
	this->signGradeReq = fr.getSignGradeReq();
	this->execGradeReq = fr.getExecGradeReq();
	return *this;
}

AForm::~AForm(void) {}

const std::string	AForm::getName(void) const {
	return this->name;
}

bool	AForm::getIsSigned(void) const {
	return this->isSigned;
}

int	AForm::getSignGradeReq(void) const {
	return this->signGradeReq;
}

int	AForm::getExecGradeReq(void) const {
	return this->execGradeReq;
}

void	AForm::beSigned(Bureaucrat br) {
	if (br.getGrade() > this->signGradeReq)
		throw(GradeTooLowException());
	this->isSigned = true;
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

std::ostream	&operator<<(std::ostream &out, AForm const &fr) {
	out << "Form " << fr.getName() << ", signed? " << fr.getIsSigned() << ", sign grade requirement " << fr.getSignGradeReq() << ", exec grade requirement " << fr.getExecGradeReq() << std::endl;
	return out;
}
