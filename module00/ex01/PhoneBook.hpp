#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define PROMPT "PhoneBook >"
# define MAXCONTACTS 8
# define INVALIDCMD "cmd not found try again with: <ADD> <SEARCH> <EXIT>"


class PhoneBook {
	public:
		void	addContact();
		void	searchContact();
	private:
		Contact	contactArray[8];
};
#endif
