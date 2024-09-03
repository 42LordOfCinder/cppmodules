#ifndef __CONTACT_H__
# define __CONTACT_H__

class	Contact {
	public:
		std::string	getFN(void);
		std::string	getLN(void);
		std::string	getNN(void);
		std::string	getPN(void);
		std::string	getDS(void);

		void		setFN(std::string fN);
		void		setLN(std::string lN);
		void		setNN(std::string nN);
		void		setPN(std::string pN);
		void		setDS(std::string dS);

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};
#endif /*__CONTACT_H__*/
