#include <string>

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

class	Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	set_name(std::string name);
	private:
		std::string	name;
};
#endif /*__ZOMBIE_H__*/
