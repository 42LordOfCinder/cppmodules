#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap {
	private:
		bool	gateKeeperMode;

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &scavTrap );
		ScavTrap &operator=( ScavTrap const &scavTrap );
		~ScavTrap( void );

		void	guardGate( void );
		void	attack( const std::string target );
};
#endif /*__SCAVTRAP_H__*/
