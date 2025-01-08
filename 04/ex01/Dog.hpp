#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal {
	private:
		std::string	type;
		Brain		*brain;

	public:
		Dog( void );
		Dog( Dog &dog );
		Dog &operator=( Dog const &dog );
		~Dog( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
		Brain		*getBrain( void ) const;
};

#endif /*__DOG_HPP__*/
