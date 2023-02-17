#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <string>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string weaponType);
		~HumanB(void);
		void	attack(void);
		void	setName(const std::string _name);
		void	setWeapon(Weapon &_weapon);
	private:
		const std::string	name;
		Weapon				*weapon;
};
#endif
