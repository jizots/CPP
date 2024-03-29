#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

Span::Span(const int &containerSize)
	:m_containerSize(containerSize),
	m_sorted(false)
{};

Span::Span(const Span &other)
	:m_elements(other.m_elements),
	m_containerSize(other.m_containerSize),
	m_sorted(other.m_sorted)
{};

Span::~Span(void)
{};

void	Span::addNumber(int element)
{
	hasContainerSpace(1);
	m_elements.push_back(element);
	// std::cout << "Added element: " << element << std::endl;
	m_sorted = false;
};

unsigned int	Span::longestSpan(void)
{
	hasMultiElement();
	std::cout << "longestSpan: ";
	if (!m_sorted)
		std::sort(m_elements.begin(), m_elements.end());
	m_sorted = true;
	return (*(m_elements.end() - 1) - *m_elements.begin());
};

unsigned int	Span::shortestSpan(void)
{
	unsigned int	result = UINT_MAX;
	unsigned int	diff;

	hasMultiElement();
	std::cout << "shortestSpan: ";
	if (!m_sorted)
		std::sort(m_elements.begin(), m_elements.end());
	m_sorted = true;
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
	std::vector<int> tmp;
	std::srand(std::time(NULL));

	hasContainerSpace(sizeAdd);
	for (unsigned int i = 0; i < sizeAdd && i < m_containerSize; ++i)
	{
		tmp.push_back(std::rand() * 2);
		std::cout << "Added element: " << tmp.back() << std::endl;
	}
	fillSpanUsingIterator(tmp.begin(), tmp.end());
	m_sorted = false;
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

void Span::hasContainerSpace(const unsigned int& size)
{
	if (m_elements.size() + size > m_containerSize)
		throw (SpanException("Too many element added"));
}


void	Span::hasMultiElement(void)
{
	if (m_elements.size() < 2)
		throw (SpanException("There is no element to compare"));
};

void	Span::fillSpanUsingIterator(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	m_elements.insert(m_elements.end(), begin, end);
}


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