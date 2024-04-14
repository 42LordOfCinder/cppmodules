#include <string>

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

class	Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	private:
		std::string	name;
};
#endif /*__ZOMBIE_H__*/
