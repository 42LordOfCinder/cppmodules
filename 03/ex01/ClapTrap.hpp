#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

class	ClapTrap {
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &clapTrap );
		ClapTrap & operator = ( ClapTrap const &clapTrap );
		~ClapTrap( void );

		void	attack( const std::string target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};
#endif /*__CLAPTRAP_H__*/
