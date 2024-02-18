#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename CONTAINER, typename target>
bool	easyfind(const CONTAINER& container, const target& data)
{
	if (std::find(container.begin(), container.end(), data) == container.end())
		return (false);
	return (true);
}

#endif