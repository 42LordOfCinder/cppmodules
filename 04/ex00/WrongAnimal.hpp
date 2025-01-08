#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <string>
# include <iostream>

class	WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal &wr );
		WrongAnimal &operator=(WrongAnimal const &wr );
		~WrongAnimal( void );

		void		makeSound( void ) const;
		std::string	getType( void ) const;
};

#endif /*__WRONGANIMAL_HPP__*/
