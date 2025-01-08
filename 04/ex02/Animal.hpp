#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>
# include <iostream>

class	Animal {
	protected:
		std::string	type;
		Animal( void );

	public:
		Animal( Animal &animal );
		Animal &operator=( Animal const &animal );
		virtual ~Animal( void );

		virtual std::string getType( void ) const;
		virtual void		makeSound( void ) const;
};

#endif /*__ANIMAL_HPP__*/
