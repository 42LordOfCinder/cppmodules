#ifndef __HUMANB_H__
# define __HUMANB_H__

# include "Weapon.hpp"

class	HumanB {
	public:
		HumanB(void);
		HumanB(std::string name) : name(name) {};
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &weapon);

	private:
		std::string	name;
		Weapon		*weapon;
};
#endif /*__HUMANB_H__*/
