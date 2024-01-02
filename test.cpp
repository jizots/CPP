#include <iostream>
#include <string>
#include <time.h>


bool	is_string_composed_f(const std::string& str, int (*f)(int))
{
	if (str.empty())
		return false;
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (!f(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

int main()
{
	float a = 2.2;

	std::cout << ++a << std::endl;
}