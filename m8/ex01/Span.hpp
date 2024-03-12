#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

template <typename T>
class Span
{
public:
	Span(const T &containerSize);
	Span(const Span &other);
	~Span(void);
	void addNumber(T);
	T shortestSpan(void);
	T longestSpan(void);
	void addManyNumbers(void);

	class TooManyElementsException : public std::exception
	{
	public:
		TooManyElementsException(const std::string msg);
		virtual ~TooManyElementsException(void) _NOEXCEPT;
		virtual const char *what() const _NOEXCEPT;

	private:
		std::string m_msg;
	};

private:
	std::vector<T>	m_elements;
	const int		m_containerSize;

private:
	Span(void);

public:
	Span<T>&	operator=(const Span &rhs);
};

# include "Span.tpp"

#endif