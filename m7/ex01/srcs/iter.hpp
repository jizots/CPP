#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename TArray>
void	iter(TArray *addressArray, size_t lengthArray, void (*func)(TArray& elem))
{
	if (addressArray == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < lengthArray; ++i)
		func(static_cast<TArray&>(addressArray[i]));
}

#endif