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
	time_t  	tmp;
	struct tm	*timeinfo;

	time(&tmp);
	timeinfo = localtime(&tmp);
	std::cout << '['\
	<< timeinfo->tm_year + 1900 << timeinfo->tm_mon + 1 << timeinfo->tm_mday\
	<< '_'\
	<< timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec\
	<< ']' << ' ';
}