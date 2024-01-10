#include "FragTrap.hpp"
#include "Libft.hpp"

FragTrap::FragTrap(void)
	:ClapTrap("Flagless")
{
	set_Hit_points(100);
	set_Energy_points(100);
	set_Attack_damage(30);
	Libft::print_colored_string_endl("Frag Constructor(default) called", green);
}

FragTrap::FragTrap(const std::string& name)
	:ClapTrap(name)
{
	set_Hit_points(100);
	set_Energy_points(100);
	set_Attack_damage(30);
	Libft::print_colored_string_endl("Frag Constructor(with name) called", green);
}

FragTrap::FragTrap(const FragTrap& other)
	:ClapTrap(other.get_name())
{
	set_Hit_points(get_Hit_points());
	set_Energy_points(get_Hit_points());
	set_Attack_damage(get_Attack_damage());
	Libft::print_colored_string_endl("Frag Copy Constructor called", green);
}

FragTrap::~FragTrap(void)
{
	Libft::print_colored_string_endl("Flag Destructor called", red);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "nikunohi!" << std::endl;
}