#include <iostream>
#include <string>

/*新しい概念の、参照（reference）を学ぶ軽めの課題*/
int	main()
{
	std::string	s1 = "HI THIS IS BRAIN";
	std::string *sPTR = &s1;
	std::string& sREF = s1;

	std::cout << "memory address of the string variable: " << &s1 << std::endl;
	std::cout << "memory address held by stringPTR     : " << sPTR << std::endl;
	std::cout << "memory address held by stringREF.    : " << &sREF << std::endl;
	std::cout << "value of the string variable  : " << s1 << std::endl;
	std::cout << "value pointed to by stringPTR : " << *sPTR << std::endl;
	std::cout << "value pointed to by stringREF : " << sREF << std::endl;
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q HI_THIS_IS_BRAIN");
}