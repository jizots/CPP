#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
public:
	Span(const int &containerSize);
	Span(const Span &other);
	~Span(void);
	void addNumber(int);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);
	void addManyNumbers(unsigned int);

	class SpanException : public std::exception
	{
	public:
		SpanException(const std::string msg);
		virtual ~SpanException(void) throw();
		virtual const char *what() const throw();

	private:
		std::string m_msg;
	};

private:
	std::vector<int>	m_elements;
	const unsigned int	m_containerSize;
	bool				m_sorted;

private:
	Span(void);
	void hasContainerSpace(const unsigned int& size);
	void hasMultiElement(void);
	void fillSpanUsingIterator(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);

public:
	Span&	operator=(const Span &rhs);
};

#endif
