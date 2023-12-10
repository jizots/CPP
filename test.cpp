#include <iostream>
#include <string>


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
	std::string str = "1";
	std::cout << is_string_composed_f(str, std::isdigit) << '\n';
}