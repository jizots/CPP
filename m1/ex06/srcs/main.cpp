#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		harl;
	std::string	arg;

	if (ac != 2)
		std::cout << "Error: Too less or many arguments." << std::endl;
	else
	{
		arg = av[1];
		harl.Harl::above(arg);
	}

	return (0);
}