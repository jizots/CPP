#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/**
 * Swap any 'same type' argument value.
 * If argument is 'Class' your class must support '=' operator.
 * @param paramA Same type as paramB.
 * @param paramB Same type as paramA.
*/
template <typename T>
void	swap(T& paramA, T& paramB)
{
	T	tmp;

	tmp = paramA;
	paramA = paramB;
	paramB = tmp;
};

/**
 * Return max any 'same type' two argument value.
 * If argument is 'Class' your class must support all comparison operator.
 * @param paramA Same type as paramB.
 * @param paramB Same type as paramA.
 * @return Reference of bigger one. If the two of them are equal, then it returns the second one.
*/
template <typename T>
T&	max(const T& paramA, const T& paramB)
{
	if (paramB >= paramA)
		return (const_cast<T&>(paramB));
	return (const_cast<T&>(paramA));
};

/**
 * Return min any 'same type' two argument value.
 * If argument is 'Class' your class must support all comparison operator.
 * @param paramA Same type as paramB.
 * @param paramB Same type as paramA.
 * @return Reference of smaller one. If the two of them are equal, then it returns the second one.
*/
template <typename T>
T&	min(const T& paramA, const T& paramB)
{
	if (paramB <= paramA)
		return (const_cast<T&>(paramB));
	return (const_cast<T&>(paramA));
};

#endif