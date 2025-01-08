#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>
# include <iostream>

class	Brain {
	private:
		std::string	*ideas;

	public:
		Brain( void );
		Brain( Brain &brain );
		Brain &operator=( Brain const &brain );
		~Brain( void );

		std::string	*getIdeas( void );
};

#endif /*__BRAIN_HPP__*/
