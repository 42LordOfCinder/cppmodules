#ifndef __HUMANA_H__
# define __HUMANA_H__

# include "Weapon.hpp"

class	HumanA {
	public:
		HumanA(void);
		HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {};
		~HumanA(void);
		void	attack(void);

	private:
		std::string	name;
		Weapon		&weapon;
};
#endif /*__HUMANA_H__*/
