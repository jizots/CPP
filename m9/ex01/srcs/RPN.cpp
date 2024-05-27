#include "RPN.hpp"

#include <iostream>

RPN::RPN(void)
{}

double RPN::Calculation(const std::string& calculationSrc)
{
	std::istringstream iss(calculationSrc);

	if (iss.fail())
		throw ("iss.fail(): Constructor");
	while (!iss.eof())
	{
		std::string token = popNextToken(iss);
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
				throw ("Error. stack does not has 2 or more items");
		}
		else if (token.size() == 0)
			continue ;
		else
			throw ("Error: " + token + " can't accept");
	}
	if (m_stack.size() == 1)
		return (m_stack.top());
	else if (m_stack.size() == 0)
		throw (std::invalid_argument("Error. Source string is empty"));
	else
		throw (std::string("Error. stack has more than one items"));
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

std::string RPN::popNextToken(std::istringstream& iss)
{
	std::string token;

	iss >> token;
	if (iss.fail())
	{
		if (iss.eof())
			return ("");
		else
			throw ("Error: iss.fail()");
	}
	return (token);
}		
