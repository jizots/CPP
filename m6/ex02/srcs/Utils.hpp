#ifndef UTILS_HPP
# define UTILS_HPP

# include "Base.hpp"

class Utils
{
public:
	static	Base*	generate(void);
	static	void	identify(Base* p);
	static	void	identify(Base& p);
private:
	Utils(void);
	~Utils(void);
};

#endif