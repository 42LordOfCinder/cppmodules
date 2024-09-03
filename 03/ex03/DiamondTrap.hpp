#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	name;
	
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &diamondTrap );
		DiamondTrap &operator=( DiamondTrap const &diamondTrap );
		~DiamondTrap( void );

		std::string		 ClapTrap::name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

		void	ScavTrap::attack( const std::string target );
		void	whoAmI( void );
};
#endif /*__DIAMONDTRAP_H__*/
