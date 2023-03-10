#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define PROMPT ">> "
# define MAX_CONTACTS 7
# define START_INDEX  0
//# define INVALIDCMD "cmd not found try again with: <ADD> <SEARCH> <EXIT>"
# define DISPLAYTABLE "INDEX     |FIRST NAME|LAST  NAME|NICK  NAME|"


// Validation fncs
bool	validatePhoneNumber(std::string phoneNumber);
bool	validateSearchIndex(std::string searchIndex);

class PhoneBook {
	public:
		void	addContact();
		void	searchContact();
	private:
		Contact	contactArray[8];
};
#endif
