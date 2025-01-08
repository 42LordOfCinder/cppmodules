#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal {
	private:
		std::string	type;

	public:
		WrongCat( void );
		WrongCat( WrongCat &wc );
		WrongCat &operator=( WrongCat const &wc );
		~WrongCat( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif /*__WRONGCAT_HPP__*/
