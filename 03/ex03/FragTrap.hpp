#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const &fragTrap );
		FragTrap &operator=( FragTrap const &FragTrap );
		~FragTrap( void );

		void	highFivesGuys( void );
};
#endif /*__FRAGTRAP_H__*/
