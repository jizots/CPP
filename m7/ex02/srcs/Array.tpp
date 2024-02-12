#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template <typename T>
Array<T>::Array(void)
	:m_array(NULL),
	m_lengthArray(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
	:m_array(NULL)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
Array<T>::Array(const unsigned int& n)
	:m_array(new T[n]),
	m_lengthArray(n)
{
	std::cout << "Unsigned int constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Destructor called" << std::endl;
	delete m_array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	std::cout << " '=' called" << std::endl;
	if (this == &rhs)
		return (*this);
	delete m_array;
	m_lengthArray = rhs.m_lengthArray;
	m_array = new T(m_lengthArray);
	for (unsigned int i = 0; i < m_lengthArray; ++i)
		m_array[i] = rhs.m_array[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int n)
{
	if (n < 0 || m_lengthArray <= n)
		throw OutOfIndexException("Out of index");
	return (m_array[n]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int n) const
{
	if (n < 0 || m_lengthArray <= n)
		throw OutOfIndexException("Out of index");
	return (m_array[n]);
}

/*Exception*/
template <typename T>
Array<T>::OutOfIndexException::OutOfIndexException(std::string msg)
	:m_msg(msg)
{}

template <typename T>
Array<T>::OutOfIndexException::~OutOfIndexException(void) _NOEXCEPT
{}

template <typename T>
const char*	Array<T>::OutOfIndexException::what() const _NOEXCEPT
{
	return (m_msg.c_str());
}

#endif