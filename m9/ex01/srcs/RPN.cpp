#include "RPN.hpp"

#include <iostream>

RPN::RPN(const char *calculationSrc)
	:m_iss((std::string(calculationSrc)))
{
	if (m_iss.fail())
		throw ("iss.fail(): Constructor");
	while (!m_iss.eof())
	{
		std::string token = popNextToken();
		if (isNumericType<uint16_t>(token))
		{
			uint16_t val = toNumericType<uint16_t>(token);
			if (9 < val)
				throw ("Error. Number's must be less than 10"); 
			m_stack.push(static_cast<double>(val));
		}
		else if (isArithmeticOparator(token))
		{
			if (1 < m_stack.size())
			{
				const double rhs = m_stack.top();
				m_stack.pop();
				const double lhs = m_stack.top();
				m_stack.pop();
				if (token == "+")
					m_stack.push(lhs + rhs);
				else if (token == "-")
					m_stack.push(lhs - rhs);
				else if (token == "/")
					m_stack.push(lhs / rhs);
				else if (token == "*")
					m_stack.push(lhs * rhs);
			}
			else
				throw ("Error. stack hasn't 2 or more item's");
		}
		else if (token.size() == 0)
			continue ;
		else
			throw ("Error: " + token + " can't accept");
	}
	if (m_stack.size() == 1)
		std::cout << m_stack.top() << std::endl;
	else
		throw (std::string("Error. stack has more than one item's"));
};

RPN::RPN(const RPN& other)
	:m_stack(other.m_stack)
{};

RPN::~RPN(void)
{};

RPN& RPN::operator=(const RPN& rhs)
{
	if (this == &rhs)
		;
	else
		m_stack = rhs.m_stack;
	return (*this);
};

bool RPN::isArithmeticOparator(const std::string& token)
{
	if (token.size() == 1 && (token == "+" || token == "-" || token == "/" || token == "*"))
		return (true);
	return (false);
};

std::string RPN::popNextToken(void)
{
	std::string token;

	m_iss >> token;
	if (m_iss.fail())
	{
		if (m_iss.eof())
			return ("");
		else
			throw ("Error: iss.fail()");
	}
	return (token);
}		
