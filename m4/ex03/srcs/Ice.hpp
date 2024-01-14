#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice& other);
	~Ice(void);
	Ice&	operator=(const Ice& rhs);
	virtual AMateria*	clone() const;

private:


};

#endif