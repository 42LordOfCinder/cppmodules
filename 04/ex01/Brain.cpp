#include "Brain.hpp"

Brain::Brain( void ) {
	this->ideas = new std::string[100];
	for ( int i = 0; i < 100; i++ )
		this->ideas[i] = "food";
	std::cout << "Brain created" << std::endl;
}

Brain::Brain( Brain &brain ) {
	std::string *oldIdeas = brain.getIdeas();
	this->ideas = new std::string[100];
	for ( int i = 0; i < 100; i++ )
		this->ideas[i] = oldIdeas[i];
	std::cout << "Brain copied" << std::endl;
}

Brain &Brain::operator=( Brain const &brain ) {
	for ( int i = 0; i < 100; i++ )
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain( void ) {
	delete [] this->ideas;
	std::cout << "Brain destroyed" << std::endl;
}

std::string	*Brain::getIdeas( void ) {
	return (this->ideas);
}
