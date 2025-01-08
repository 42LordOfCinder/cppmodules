#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class	Dog: public Animal {
	private:
		std::string	type;

	public:
		Dog( void );
		Dog( Dog &dog );
		Dog &operator=( Dog const &dog );
		~Dog( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif /*__DOG_HPP__*/
