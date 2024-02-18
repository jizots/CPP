#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
public:
	Span(const unsigned int& containerSize);
	Span(const Span& other);
	~Span(void);

	class TooManyElementsException : public std::exception
	{
	public:
	private:
	};

private:
	std::vector<int>	m_uiv;
	const unsigned int	m_containerSize;
private:
	Span(void);

public:
	Span&	operator=(const Span& rhs);
};

#endif