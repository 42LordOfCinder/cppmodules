#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal {
	private:
		std::string	type;
		Brain		*brain;
	
	public:
		Cat( void );
		Cat( Cat &cat );
		Cat &operator=( Cat const &cat );
		~Cat( void );

		void		makeSound( void ) const;
		std::string	getType( void ) const;
		Brain		*getBrain( void ) const;
};

#endif /*__CAT_HPP__*/
