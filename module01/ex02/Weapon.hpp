#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	public:
		Weapon(void);
		~Weapon(void);
		void setType(const std::string _type);
		const std::string *getType(void);
	private:
		std::string type;
};
#endif
