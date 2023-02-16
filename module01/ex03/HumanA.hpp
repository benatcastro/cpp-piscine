#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <string>
# include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string weaponType, Weapon &weapon);
		~HumanA(void);
		void	attack(void);
		void	setName(const std::string _name);
	private:
		Weapon	&weapon;
		const std::string	name;
};
#endif
