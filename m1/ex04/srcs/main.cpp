#include "StringReplace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Arguments is not correct. [In_filename] [string to search] [string to replace]" << std::endl;
		return (1);
	}
	StringReplace sr(av[1]);
	std::string	s0(av[1]), s1(av[2]), s2(av[3]);
	sr.StringReplace::set_ofstream(s0 + ".replace");
	sr.replace_to_newfile(s1, s2);
	std::cout << "New file created!" << std::endl;
}

__attribute__((destructor))
static void destructor()
{
    system("leaks -q Sed_is_for_losers");
}