#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class	Cat: public Animal {
	private:
		std::string	type;
	
	public:
		Cat( void );
		Cat( Cat &cat );
		Cat &operator=( Cat const &cat );
		~Cat( void );

		void		makeSound( void ) const;
		std::string	getType( void ) const;
};

#endif /*__CAT_HPP__*/
