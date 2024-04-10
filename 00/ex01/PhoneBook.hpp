#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"

class	PhoneBook {
	public:
		int		i;
		Contact	contacts[8];

		PhoneBook(void);
		void	addContact(void);
		void	printContact(void);
};
#endif
