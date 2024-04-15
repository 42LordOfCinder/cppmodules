#ifndef __WEAPON_H__
# define __WEAPON_H__

# include <string>

class	Weapon {
	public:
		Weapon(std::string type) : type(type) {};
		~Weapon(void);
		std::string	&getType(void);
		void		setType(std::string newType);

	private:
		std::string	type;
};
#endif /*__WEAPON_H__*/
