#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename TArray, typename TFunction>
void	iter(TArray *addressArray, size_t lengthArray, TFunction)
{
	if (addressArray == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < lengthArray; ++i)
		func(addressArray[i]);
}

#endif