#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		void addContact(void);
		void searchContact(void);
	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;


};

#endif
