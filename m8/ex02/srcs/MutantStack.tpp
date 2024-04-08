#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
	:std::stack<T>()
{};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	:std::stack<T>(other)
{};

template<typename T>
MutantStack<T>::~MutantStack(void){};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
};
