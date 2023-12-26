#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "constructor called\n";
}

Harl::~Harl(void)
{
	std::cout << "destructor called\n";
}

void	Harl::debug( void )
{
	std::cout << "Debug" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "Info" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "Warning" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "Error" << std::endl;
}

void	Harl::complain( std::string level )
{
	t_complains	comps[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

    while (i < 4)
	{
        if (!levels[i].compare(level))
		{
            (this->*comps[i])();
            break;
        }
		i++;
	}
	if (i == 4)
		std::cout << "I'm Nameless!!\n";
}
