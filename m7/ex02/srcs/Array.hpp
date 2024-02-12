#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <string>

template <typename T>
class Array
{
public:
	Array(void);
	Array(const Array& other);
	Array(const unsigned int& n);
	~Array(void);

	class OutOfIndexException : public std::exception
	{
	public:
		OutOfIndexException(std::string msg);
		virtual ~OutOfIndexException(void) _NOEXCEPT;
		virtual const char*	what() const _NOEXCEPT;
	private:
		std::string	m_msg;
	};

private:
	T				*m_array;
	unsigned int	m_lengthArray;

public:
	Array<T>&	operator=(const Array& rhs);
	T&			operator[](unsigned int n);
	const T&	operator[](unsigned int n) const;
};

# include "Array.tpp"

#endif