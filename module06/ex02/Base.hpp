#ifndef BASE_HPP
# define BASE_HPP

class Base {
public:
	Base();
	virtual ~Base();


	static Base		*generate(void);
	static void		identify(Base *p);
	static void		identify(Base &p);
	virtual void	dummy() = 0;

};

#endif
