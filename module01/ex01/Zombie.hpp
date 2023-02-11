#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# define ZOMBIECOUNT 3
# define ZOMBIENAME "Bob"
class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void	setName(const std::string _name);
		void	announce(void);
	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);
#endif
