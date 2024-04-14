#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "Contact.hpp"

class	PhoneBook {
	public:
		int		i;
		Contact	contacts[8];

		PhoneBook(void);
		void	addContact(void);
		void	printContact(void);
};
#endif /*__PHONEBOOK_H__*/
