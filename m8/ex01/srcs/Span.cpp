#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

Span::Span(const int &containerSize)
	:m_containerSize(containerSize)
{};

Span::Span(const Span &other)
	:m_elements(other.m_elements),
	m_containerSize(other.m_containerSize)
{};

Span::~Span(void)
{};

void	Span::addNumber(int element)
{
	if (m_elements.size() < m_containerSize)
	{
		m_elements.push_back(element);
		// std::cout << "Added element: " << element << std::endl;
	}
	else
		throw (SpanException("[Error] Too many element added."));
};

unsigned int	Span::longestSpan(void)
{
	hasMultiElement();
	std::cout << "longestSpan: ";
	std::sort(m_elements.begin(), m_elements.end());
	return (*(m_elements.end() - 1) - *m_elements.begin());
};

unsigned int	Span::shortestSpan(void)
{
	unsigned int	result = UINT_MAX;
	unsigned int	diff;

	hasMultiElement();
	std::cout << "shortestSpan: ";
	std::sort(m_elements.begin(), m_elements.end());
	for (unsigned int i = 0; i < m_elements.size() - 1; ++i)
	{
		diff = m_elements[i + 1] - m_elements[i];
		if (diff < result)
			result = diff;
	}
	return (result);
};

void	Span::addManyNumbers(unsigned int sizeAdd)
{
	std::srand(std::time(NULL));
	for (unsigned int i = 0; i < sizeAdd && i < m_containerSize; ++i)
		addNumber(std::rand());
};

Span&	Span::operator=(const Span &rhs)
{
	if (&rhs == this)
		return (*this);
	if (m_containerSize == rhs.m_containerSize)
		m_elements = rhs.m_elements;
	else
		throw (SpanException("Copy assignment failed: Because number of element is not same"));
	return (*this);
};

void	Span::hasMultiElement(void)
{
	if (m_elements.size() < 2)
		throw (SpanException("There is no element to compare"));
};

/*****
 * Exception
*****/

Span::SpanException::SpanException(const std::string msg)
	:m_msg(msg)
{};

Span::SpanException::~SpanException(void) throw()
{}

const char * Span::SpanException::what() const throw()
{
	return (m_msg.c_str());
};