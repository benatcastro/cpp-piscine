#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	public:
		// Setters
		void	setFirstName(const std::string _firstName);
		void	setLastName(const std::string _LastName);
		void	setNickName(const std::string _NickName);
		void	setPhoneNumber(const std::string _PhoneNumber);
		void	setSecret(const std::string _secret);

		// Getters
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getSecret(void);
	private:

		// Contact Index used for search fnc
		int			index;

		// Contact Data
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	secret;


};

#endif
